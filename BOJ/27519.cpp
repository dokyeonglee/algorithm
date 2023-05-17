#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(100001, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 100000; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 100000; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i <= 100000; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    vector<long long> dp(100001);
    dp[0] = 1;
    
    for(int i = 0; i < prime.size(); i++){
        for(int j = prime[i]; j <= 100000; j++){
            dp[j] += dp[j - prime[i]];
            dp[j] %= 1000000007;
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}