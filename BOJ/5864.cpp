#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate_doubled_min_wifi_cost(vector<int>& cows, const int a, const int b) {
    sort(cows.begin(), cows.end());

    int doubled_cost = 2 * a;
    for (int i = 1; i < cows.size(); ++i) {
        doubled_cost += min(2 * a, (cows[i] - cows[i - 1]) * b);
    }

    return doubled_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> cows(n);
    for (int& cow : cows) {
        cin >> cow;
    }

    int doubled_cost = calculate_doubled_min_wifi_cost(cows, a, b);
    cout << doubled_cost / 2 << (doubled_cost % 2 ? ".5" : "") << '\n';

    return 0;
}