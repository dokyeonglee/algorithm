#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_TOTAL_VOLUME = 100000;
constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<int> volumes(b);
    for (int i = 0; i < b; ++i) {
        cin >> volumes[i];
    }

    vector<int> total_volumes_in_field(n);
    for (int i = 0; i < n; ++i) {
        cin >> total_volumes_in_field[i];
    }

    vector<int> dp(MAX_TOTAL_VOLUME + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < volumes.size(); ++i) {
        for (int j = volumes[i]; j <= MAX_TOTAL_VOLUME; ++j) {
            dp[j] = min(dp[j], dp[j - volumes[i]] + 1);
        }
    }

    int answer = -1;
    int current_min_cows = 0;
    int current_total_volume = 0;
    for (int i = 0; i < n; ++i) {
        if (total_volumes_in_field[i] == 0) {
            current_min_cows = 0;
            continue;
        }
        current_total_volume = max(current_total_volume - 1, 0);
        if (total_volumes_in_field[i] != current_total_volume) {
            current_min_cows += dp[total_volumes_in_field[i] - current_total_volume];
            answer = max(answer, current_min_cows);
            current_total_volume = total_volumes_in_field[i];
        }
        if (answer == INF) {
            answer = -1;
            break;
        }
    }

    cout << answer << '\n';

    return 0;
}