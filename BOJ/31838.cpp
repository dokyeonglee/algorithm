#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> value_psum(n + 1 + 2 * k);

    for(int i = k; i < n + k; i++){
        cin >> value_psum[i];
    }

    for(int i = 1; i < value_psum.size(); i++){
        value_psum[i] += value_psum[i - 1];
    }

    vector<long long> dp(value_psum.size());
    vector<long long> dp2(value_psum.size());

    for(int i = 1; i < dp.size(); i++){
        dp[i] = dp[i - 1];
        if(k <= i){
            dp[i] = max(dp[i], dp2[i - k] + value_psum[i]);
        }
        dp2[i] = max(dp2[i - 1], dp[i] - value_psum[i]);
    }

    cout << dp.back();

    return 0;
}