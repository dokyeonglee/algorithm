#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    vector<int> read_cost(31);
    vector<int> dp(31);

    while(t--){

        int n, m, copy_cost;
        cin >> n >> m >> copy_cost;

        for(int i = 1; i <= m; i++){
            cin >> read_cost[i];
        }

        fill(dp.begin(), dp.end(), INF);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;

            for(int j = 0; j <= m; j++){
                if(dp[j] == INF){
                    continue;
                }
                if(j != x){
                    dp[x] = min(dp[x], dp[j] + copy_cost);
                    dp[j] += read_cost[x];
                }
            }
        }

        cout << *min_element(dp.begin(), dp.end()) << '\n';

    }

    return 0;

}