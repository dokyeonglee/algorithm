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

    vector<long long> fac(1e6 + 1);
    vector<long long> fac_inv(1e6 + 1);

    fac[0] = 1;
    for(int i = 1; i <= 1e6; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv[1e6] = pow(fac[1e6], mod - 2, mod);
    for(int i = 1e6; i >= 1; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    long long answer = 1;

    int n, d, p;
    cin >> n >> d >> p;
    
    vector<long long> pos(d, 1);

    int cnt = 0;
    int diff;

    for(int i = 0; i < p; i++){

        cnt = 0;

        for(int j = 0; j < d; j++){

            int x;
            cin >> x;

            diff = x - pos[j];
            cnt += diff;
            answer = answer * fac_inv[diff] % mod;
            pos[j] = x;

        }

        answer = answer * fac[cnt] % mod;

    }

    cnt = 0;

    for(int j = 0; j < d; j++){
        diff = n - pos[j];
        cnt += diff;
        answer = answer * fac_inv[diff] % mod;
    }
    answer = answer * fac[cnt] % mod;

    cout << answer;

    return 0;
}