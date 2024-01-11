#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1121, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 1120; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 1120; j += i){
                is_prime[j] = false;
            }
        }
    }

    vector<int> prime;
    for(int i = 2; i <= 1120; i++){
        if(is_prime[i]){
            prime.push_back(i);
        }
    }

    vector<vector<int>> dp(1121, vector<int>(15));
    dp[0][0] = 1;

    for(int i = 0; i < prime.size(); i++){
        for(int j = 1120; j >= prime[i]; j--){
            for(int x = 1; x <= 14; x++){
                dp[j][x] += dp[j - prime[i]][x - 1];
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << "\n";
    }

    return 0;
}