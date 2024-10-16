#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){

    long long result = 1;

    while(n > 0){
        if(n % 2){
            result = result * a % mod;
        }
        a = a * a % mod;
        n /= 2;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n, m;
    cin >> n >> m;

    long long fac = 1;

    for(int i = 1; i <= n; i++){
        fac = i * fac % mod;
    }

    vector<long long> fac_inv(n + 1);

    fac_inv[n] = pow(fac, mod - 2, mod);

    for(int i = n; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    long long answer = pow(2, n - m, mod) * fac % mod;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        answer = answer * fac_inv[x] % mod;
    }

    cout << answer;

    return 0;
}