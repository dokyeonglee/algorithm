#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> weights(2 << n);
    for (int i = 2; i < weights.size(); ++i) {
        cin >> weights[i];
    }

    int answer = 0;
    for (int i = 2; i < weights.size(); ++i) {
        answer += weights[i];
    }

    for (int i = weights.size() - 1; i >= 3; i -= 2) {
        weights[i >> 1] += max(weights[i], weights[i - 1]);
        answer += abs(weights[i] - weights[i - 1]);
    }

    cout << answer << '\n';

    return 0;
}