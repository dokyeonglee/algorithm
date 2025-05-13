#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, required_cpu, required_memory;
    cin >> n >> required_cpu >> required_memory;

    const int MAX_PRIORITY_SUM = 5 * n;

    vector<vector<int>> dp(required_cpu + 1, vector<int>(MAX_PRIORITY_SUM + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        int cpu, memory, priority;
        cin >> cpu >> memory >> priority;

        for (int c = required_cpu; c >= 0; c--) {
            for (int p = MAX_PRIORITY_SUM - priority; p >= 0; p--) {
                if (dp[c][p] == -1) {
                    continue;
                }

                int new_cpu = min(c + cpu, required_cpu);
                int new_priority = p + priority;
                int new_memory = dp[c][p] + memory;

                dp[new_cpu][new_priority] = max(dp[new_cpu][new_priority], new_memory);
            }
        }
    }

    for (int priority = 0; priority <= MAX_PRIORITY_SUM; priority++) {
        if (dp[required_cpu][priority] >= required_memory) {
            cout << priority;
            return 0;
        }
    }

    cout << -1;

    return 0;

}