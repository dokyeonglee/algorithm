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

    vector<long long> fac(2e6 + 1);
    vector<long long> fac_inv(2e6 + 1);
    
    fac[0] = 1;
    fac_inv[0] = 1;

    for(int i = 1; i <= 2e6; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    fac_inv.back() = pow(fac.back(), mod - 2, mod);
    for(int i = 2e6; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> arr(k);
    for(int i = 0; i < k; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    long long answer = fac[n + m] * fac_inv[n] % mod * fac_inv[m] % mod;

    for(int i = 1; i < (1 << k); i++){

        pair<int, int> now = make_pair(0, 0);
        long long result = 1;

        for(int j = 0; j < k; j++){
            if(i & (1 << j)){
                if(now.second > arr[j].second){
                    result = 0;
                    break;
                }
                int dr = arr[j].first - now.first;
                int dc = arr[j].second - now.second;
                result *= fac[dr + dc] * fac_inv[dr] % mod * fac_inv[dc] % mod;
                result %= mod;
                now = arr[j];
            }
        }

        result *= fac[n - now.first + m - now.second] * fac_inv[n - now.first] % mod * fac_inv[m - now.second] % mod;
        result %= mod;

        if(__builtin_popcount(i) % 2){
            answer = (answer - result + mod) % mod;
        }else{
            answer = (answer + result) % mod;
        }

    }

    cout << answer;

    return 0;

}