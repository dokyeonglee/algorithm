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

    const int mod = 998244353;

    vector<long long> fac(2e5 + 1);

    fac[0] = 1;

    for(int i = 1; i <= 2e5; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(2e5 + 1);

    fac_inv[2e5] = pow(fac[2e5], mod - 2, mod);

    for(int i = 2e5; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int n, m;
    cin >> n >> m;

    long long p = pow(25, n - m, mod);
    long long twenty_five_inv = pow(25, mod - 2, mod);

    long long exactly_m = p * fac_inv[m] % mod * fac_inv[n - m] % mod;
    long long m_or_more = exactly_m;

    for(int i = m + 1; i <= n; i++){
        p = p * twenty_five_inv % mod;
        m_or_more = (m_or_more + p * fac_inv[i] % mod * fac_inv[n - i] % mod) % mod;
    }

    exactly_m = exactly_m * fac[n] % mod;
    m_or_more = m_or_more * fac[n] % mod;

    cout << (exactly_m * (2 * m_or_more - exactly_m) % mod + mod) % mod;

    return 0;
}