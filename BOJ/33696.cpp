#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, const int mod){
    long long result = 1;
    while(n){
        if(n & 1){
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

long long get_number_of_udp_string(vector<long long>& fac, vector<long long>& fac_inv, int n, const int mod){
    return fac[3 * n] * fac_inv[n] % mod * fac_inv[n] % mod * fac_inv[n] % mod;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n;
    cin >> n;

    vector<long long> fac(3 * n + 1);
    fac[0] = 1;

    for(int i = 1; i < fac.size(); i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(n + 1);

    fac_inv[n] = pow(fac[n], mod - 2, mod);

    for(int i = n; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    vector<long long> dp(n + 1);

    vector<long long> number_of_udp_string(n + 1);
    for(int i = 1; i <= n; i++){
        number_of_udp_string[i] = get_number_of_udp_string(fac, fac_inv, i, mod); 
    }

    for(int i = 1; i <= n; i++){
        dp[i] = number_of_udp_string[i];
        for(int j = 1; j < i; j++){
            dp[i] -= dp[j] * number_of_udp_string[i - j] % mod;
        }
        dp[i] = (dp[i] % mod + mod) % mod;
    }

    cout << dp[n];

    return 0;

}