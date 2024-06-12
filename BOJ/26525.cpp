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

    vector<long long> fac(10001);

    const int mod = 1e9 + 7;

    fac[0] = 1;

    for(int i = 1; i <= 10000; i++){
        fac[i] = i * fac[i - 1] % mod;
    }

    vector<long long> fac_inv(10001);

    fac_inv[10000] = pow(fac[10000], mod - 2, mod);

    for(int i = 10000; i > 0; i--){
        fac_inv[i - 1] = i * fac_inv[i] % mod;
    }

    int n, k;
    cin >> n >> k;

    vector<string> arr(n);

    for(auto& a : arr){
        cin >> a;
    }

    int total_blank_cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '0'){
                total_blank_cnt++;
            }
        }
    }

    long long answer = 0;

    int line_blank_cnt;

    for(int i = 0; i < n; i++){
        line_blank_cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[i][j] == '0'){
                line_blank_cnt++;
            }
        }
        if(k < line_blank_cnt){
            continue;
        }
        answer += fac[total_blank_cnt - line_blank_cnt] * fac_inv[k - line_blank_cnt] % mod;
    }

    for(int i = 0; i < n; i++){
        line_blank_cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j][i] == '0'){
                line_blank_cnt++;
            }
        }
        if(k < line_blank_cnt){
            continue;
        }
        answer += fac[total_blank_cnt - line_blank_cnt] * fac_inv[k - line_blank_cnt] % mod;
    }

    line_blank_cnt = 0;

    for(int i = 0; i < n; i++){
        if(arr[i][i] == '0'){
            line_blank_cnt++;
        }
    }

    if(line_blank_cnt <= k){
        answer += fac[total_blank_cnt - line_blank_cnt] * fac_inv[k - line_blank_cnt] % mod;
    }

    line_blank_cnt = 0;

    for(int i = 0; i < n; i++){ 
        if(arr[i][n - 1 - i] == '0'){
            line_blank_cnt++;
        }
    }

    if(line_blank_cnt <= k){
        answer += fac[total_blank_cnt - line_blank_cnt] * fac_inv[k - line_blank_cnt] % mod;
    }

    answer %= mod;

    answer *= (fac[k] * fac_inv[total_blank_cnt] % mod) * fac[n * n] % mod;

    cout << answer % mod;

    return 0;
}