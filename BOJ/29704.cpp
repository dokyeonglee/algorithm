#include <iostream>
#include <vector>

using namespace std;

struct Assignment {
    int days;
    int penalty;
};

int calculate_min_penalty(const vector<Assignment>& assignments, const int time_limit) {
    vector<int> dp(time_limit + 1);

    int total_penalty = 0;
    for (auto& [days, penalty] : assignments) {
        total_penalty += penalty;

        for (int i = time_limit; i >= days; --i) {
            dp[i] = max(dp[i], dp[i - days] + penalty);
        }
    }

    total_penalty -= dp[time_limit];

    return total_penalty;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<Assignment> assignments(n);
    for (auto& assignment : assignments) {
        cin >> assignment.days >> assignment.penalty;
    }

    cout << calculate_min_penalty(assignments, t) << '\n';

    return 0;
}