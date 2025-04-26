#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> dumpling_price(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> dumpling_price[i];
    }

    sort(dumpling_price.rbegin(), dumpling_price.rend() - 1);

    vector<long long> dp(m + 10001, 1e9);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int c, e;
        cin >> c >> e;
        for(int j = m + c; j >= c; j--){
            dp[j] = min(dp[j], dp[j - c] + e);
        }
    }

    for(int i = m + 10000; i > 0; i--){
        dp[i - 1] = min(dp[i - 1], dp[i]);
    }

    long long answer = 0;
    long long sum_of_dumpling_price = 0;

    for(int i = 1; i <= m; i++){
        sum_of_dumpling_price += dumpling_price[i];
        answer = max(answer, sum_of_dumpling_price - dp[i]);
    }

    cout << answer;

    return 0;

}