#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    auto result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2){
        result = result * a % mod;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> fac(2e6 + 1);
    vector<long long> fac_inv(2e6 + 1);

    const int mod = 1e9 + 7;

    fac[0] = 1;

    for(int i = 1; i <= 2e6; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv[2e6] = pow(fac[2e6], mod - 2, mod);
    for(int i = 2e6; i >= 1; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    long long n, k;
    cin >> n >> k;

    long long answer = 0;
    
    for(int i = 1; i < n; i++){
        long long result = pow(i, k, mod) * (2 * i + 1) % mod;
        result = result * (fac_inv[n - i] * fac_inv[n + i + 1] % mod) % mod;
        answer = (answer + result) % mod;
    }

    answer = (answer * fac[2 * n]) % mod;
    answer = (answer + pow(n, k, mod)) % mod;

    cout << answer;

    return 0;
}