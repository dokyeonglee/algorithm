#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, k;
    cin >> n >> k;

    vector<long long> dp(55);
    dp[0] = 1;

    int cnt = 0;
    long long temp = n;

    while(temp > 0){
        cnt++;
        temp /= k;
        dp[cnt] = k * dp[cnt - 1];
    }

    long long answer = 0;

    for(int i = cnt - 1; i >= 0; i--){
        if(i % 2 == 0){
            answer += dp[i / 2] * (n % dp[i + 1] / dp[i]);
            if(i == 0){
                answer++;
            }
        }else{
            if(n % dp[i + 1] / dp[i]){
                answer += dp[(i + 1) / 2];
                break;
            }
        }
    }

    cout << answer;

    return 0;

}