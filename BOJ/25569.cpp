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

    vector<long long> fac(6e5 + 1);
    vector<long long> fac_inv(6e5 + 1);
    
    fac[0] = 1;
    fac_inv[0] = 1;

    for(int i = 1; i <= 6e5; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv.back() = pow(fac.back(), mod - 2, mod);
    for(int i = 6e5; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    long long answer = 1;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        long long result = fac[a + b] * fac_inv[a] % mod;
        result = (result * fac_inv[b]) % mod - 1;
        answer = (answer * result) % mod;
    }

    cout << answer;

    return 0;

}