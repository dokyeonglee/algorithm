#include <iostream>
#include <vector>

using namespace std;

constexpr int NEG_INF = -1e9;

int calculate_max_prev_rebate(const vector<int>& dp, const int pos, const int max_step) {
    int prev_rebate = NEG_INF;
    for (int step = 1; step <= max_step; ++step) {
        if (dp[pos - step] != NEG_INF){
            prev_rebate = max(prev_rebate, dp[pos - step]);
        }
    }
    return prev_rebate;
}

int calculate_max_rebate(const vector<int>& rebates, const int max_step, const int max_turns) {
    const int board_size = rebates.size();
    const int end_of_board = board_size - 1;

    vector<int> dp(board_size, NEG_INF);
    dp[0] = 0;

    for (int turn = 1; turn <= max_turns; ++turn) {
        for (int pos = end_of_board; pos >= 1; --pos) {
            dp[pos] = calculate_max_prev_rebate(dp, pos, min(pos, max_step)) + rebates[pos];
        }
    }

    return dp[end_of_board];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n, max_step, max_turns;
        cin >> n >> max_step >> max_turns;

        if (n == 0) {
            break;
        }

        vector<int> rebates(n + 2);
        for (int pos = 1; pos <= n; ++pos) {
            cin >> rebates[pos];
        }

        cout << calculate_max_rebate(rebates, max_step, max_turns) << '\n';
    }

    return 0;
}