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

    const int mod = 1e9 + 7;

    vector<long long> fac(5e5 + 1);

    fac[0] = 1;

    for(int i = 1; i <= 5e5; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(5e5 + 1);

    fac_inv[5e5] = pow(fac[5e5], mod - 2, mod);
    
    for(int i = 5e5; i >= 1; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    long long answer = 0;

    for(int i = 1; i <= n; i++){
        answer = (answer + (arr[i] - arr[i - 1]) * fac[arr[n] - arr[i - 1] - 1] % mod * fac_inv[arr[n] - arr[i - 1]] % mod) % mod;
    }

    answer = answer * fac[arr[n]] % mod;

    for(int i = 1; i <= n; i++){
        answer = answer * fac_inv[arr[i] - arr[i - 1]] % mod;
    }

    cout << answer;

    return 0;
}