#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using ll = long long;

constexpr int BAR_WEIGHT = 20;
constexpr int PLATE_TYPE[] = {20, 15, 10, 5};

ll count_plates_for_weight(ll weight) {
    ll plates = 0;
    for (const int plate : PLATE_TYPE) {
        plates += weight / plate;
        weight %= plate;
    }

    return plates;
}

ll calculate_total_moved_weight(const vector<int>& target_weights) {
    ll total_moved_weight = target_weights[0] - BAR_WEIGHT;
    for (int i = 1; i < target_weights.size(); ++i) {
        total_moved_weight += abs(target_weights[i] - target_weights[i - 1]);
    }
    return total_moved_weight;
}

ll calculate_total_moved_plates(const vector<int>& target_weights) {
    stack<int> barbell_states;
    barbell_states.push(BAR_WEIGHT);

    ll total_moved_plates = 0;

    for (const int weight : target_weights) {
        while (barbell_states.size() > 1 && barbell_states.top() > weight) {
            int prev_weight = barbell_states.top();
            barbell_states.pop();

            int removed_weight = prev_weight - max(barbell_states.top(), weight);
            total_moved_plates += 4 * count_plates_for_weight(removed_weight / 2);
        }

        if (barbell_states.top() != weight) {
            barbell_states.push(weight);
        }
    }

    return total_moved_plates;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> target_weights(n);
    for (int& weight : target_weights) {
        cin >> weight;
    }
    target_weights.push_back(BAR_WEIGHT);

    ll total_moved_weight = calculate_total_moved_weight(target_weights);
    ll total_moved_plates = calculate_total_moved_plates(target_weights);

    cout << total_moved_weight << ' ' << total_moved_plates << '\n';

    return 0;
}