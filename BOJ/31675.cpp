#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll calculate_min_energy(const vector<int>& resistance) {
    const int n = resistance.size();

    if (n == 1) {
        return resistance[0];
    }

    if (n == 2) {
        return min(resistance[0], resistance[1]);
    }

    vector<long long> dp(n + 2);

    dp[0] = resistance[0];
    dp[1] = resistance[1];
    dp[2] = resistance[0] + resistance[2];

    for (int i = 3; i < n; ++i) {
        dp[i] = min(dp[i - 2], dp[i - 3]) + resistance[i];
    }

    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> resistance(n);
    ll total_energy = 0;

    for (auto& x : resistance) {
        cin >> x;
        total_energy += x;
    }

    ll min_energy = calculate_min_energy(resistance);
    cout << total_energy - min_energy;

    return 0;
}