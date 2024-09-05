#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> foods(n + 1);

    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        while(x--){
            int p, v;
            cin >> p >> v;
            foods[p].emplace_back(i, v);
        }
    }

    long long answer = 0;

    vector<long long> dp(2);

    for(int i = 1; i <= n; i++){
        if(foods[i].size() > 0){
            dp[0] = 0;
            dp[1] = foods[i][0].second;
            for(int j = 1; j < foods[i].size(); j++){
                if(foods[i][j].first - foods[i][j - 1].first == 1){
                    auto temp = dp[1];
                    dp[1] = max(dp[1], dp[0] + foods[i][j].second);
                    dp[0] = max(dp[0], temp);
                }else{
                    dp[0] = max(dp[0], dp[1]);
                    dp[1] += foods[i][j].second;
                }
            }
            answer += max(dp[0], dp[1]);
        }
    }

    cout << answer;

    return 0;
}