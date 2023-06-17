#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int coin[] = {1, 10, 25};

    vector<int> dp(100, 987654321);

    dp[0] = 0;

    for(int i = 0; i < sizeof(coin) / sizeof(int); i++){
        dp[coin[i]] = 1;
        for(int j = coin[i]; j < 100; j++){
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }    
    }

    while(t--){

        long long n;
        cin >> n;

        long long answer = 0;

        while(n > 0){
            answer += dp[n % 100];
            n /= 100;
        }

        cout << answer << "\n";

    }    

    return 0;
}