#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long pow(long long a, long long n, long long mod){
    if(n == 0){
        return 1;
    }
    long long result = pow(a, n / 2, mod);
    result = result * result % mod;
    if(n % 2 == 1){
        result = result * a % mod;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    vector<long long> fac(4e5 + 1);
    vector<long long> fac_inv(4e5 + 1);
    
    fac[0] = 1;
    fac_inv[0] = 1;

    for(int i = 1; i <= 4e5; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv[400000] = pow(fac[400000], mod - 2, mod);
    for(int i = 400000; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int m;
    cin >> m;

    long long answer = 0;

    for(int i = 3; i <= m; i++){
        long long result = fac[2 * i] * fac_inv[i] % mod;
        result = result * fac_inv[i] % mod;
        answer = (answer + result) % mod;
    }

    cout << answer;

    return 0;
    
}