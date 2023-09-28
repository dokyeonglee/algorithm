#include <iostream>
#include <vector>

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

    vector<long long> fac(501, 1);
    for(int i = 1; i <= 500; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(501);
    fac_inv[500] = pow(fac[500], mod - 2, mod);

    for(int i = 500; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int q;
    cin >> q;

    while(q--){

        int n;
        cin >> n;

        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        long long answer = 1;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                answer = answer * (arr[j] - arr[i]) % mod;
            }
        }

        for(int i = 0; i < n; i++){
            answer = answer * fac_inv[i] % mod;
        }

        cout << (answer + mod) % mod << "\n";
    }


    return 0;
}