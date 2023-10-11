#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){    

    if(n == 0){
        return 1;
    }

    long long result = pow(a, n / 2, mod);
    result = result * result % mod;

    if(n % 2){
        result = result * a % mod;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    vector<long long> fac(2e6 + 1, 1);
    vector<long long> fac_inv(1e6 + 2);

    for(int i = 1; i <= 2e6; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv[1e6 + 1] = pow(fac[1e6 + 1], mod - 2, mod);
    for(int i = 1e6 + 1; i >= 1; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        cout << fac[2 * n] * fac_inv[n + 1] % mod * fac_inv[n] % mod << "\n";

    }

    return 0;
}