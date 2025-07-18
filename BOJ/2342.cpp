#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1000000000;
constexpr int move_cost[5][5] = {
    {INF, 2, 2, 2, 2},
    {INF, 1, 3, 4, 3},
    {INF, 3, 1, 3, 4},
    {INF, 4, 3, 1, 3},
    {INF, 3, 4, 3, 1}
};

int calculate_min_strength(const vector<int>& directions) {
    vector<vector<int>> dp(2, vector<int>(5, INF));
    dp[0][0] = move_cost[0][directions[0]];

    int toggle = 1;

    for (int i = 1; i < directions.size(); ++i) {
        int previous = directions[i - 1];
        int current = directions[i];

        for (int j = 0; j < 5; ++j) {
            dp[toggle][j] = dp[toggle ^ 1][j] + move_cost[previous][current];
        }

        for (int j = 0; j < 5; ++j) {
            dp[toggle][previous] = min(dp[toggle][previous], dp[toggle ^ 1][j] + move_cost[j][current]);
        }

        toggle ^= 1;
    }

    return *min_element(dp[toggle ^ 1].begin(), dp[toggle ^ 1].end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> directions;
    while (1) {
        int current;
        cin >> current;

        if (current == 0) {
            break;
        }

        directions.push_back(current);
    }
    
    cout << calculate_min_strength(directions);

    return 0;
}