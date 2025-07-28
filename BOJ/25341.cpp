#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

struct Neuron {
    vector<int> input_indices;
    vector<ll> weights;
    ll bias = 0;
};

Neuron read_hidden_neuron() {
    Neuron hidden;

    int c;
    cin >> c;

    hidden.input_indices.resize(c);
    hidden.weights.resize(c);

    
    for (int& index : hidden.input_indices) {
        cin >> index;
        --index;
    }

    for (ll& weights : hidden.weights) {
        cin >> weights;
    }

    cin >> hidden.bias;
    return hidden;
}

Neuron build_output_neuron(const vector<Neuron>& hidden_layer, const int n) {
    const int m = hidden_layer.size();

    Neuron output_neuron;
    output_neuron.weights.resize(n);

    for (auto& hidden : hidden_layer) {
        ll output_weight;
        cin >> output_weight;

        output_neuron.bias += output_weight * hidden.bias;
        for (int i = 0; i < hidden.input_indices.size(); ++i) {
            output_neuron.weights[hidden.input_indices[i]] += output_weight * hidden.weights[i];
        }
    }

    ll bias;
    cin >> bias;

    output_neuron.bias += bias;
    return output_neuron;
}

ll compute(const Neuron& hidden, const vector<int>& inputs) {
    ll output = hidden.bias;
    for (int i = 0; i < inputs.size(); ++i) {
        output += hidden.weights[i] * inputs[i];
    }

    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<Neuron> hidden_layer(m);
    for (auto& hidden : hidden_layer) {
        hidden = read_hidden_neuron();
    }

    Neuron output_neuron = build_output_neuron(hidden_layer, n);
 
    while (q--) {
        vector<int> inputs(n);
        for (int& i : inputs) {
            cin >> i;
        }

        cout << compute(output_neuron, inputs) << '\n';
    }


    return 0;
}