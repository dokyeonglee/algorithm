#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){

    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < brr[0].size(); j++){
            for(int k = 0; k < arr[0].size(); k++){
                result[i][j] += arr[i][k] * brr[k][j];
                result[i][j] %= mod;
            }
        }
    }

    return result;

}

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n, long long mod){

    if(n == 1){
        return arr;
    }

    auto result = pow(arr, n / 2, mod);
    result = mat_mul(result, result, mod);

    if(n % 2 == 1){
        result = mat_mul(result, arr, mod);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    vector<long long> arr(10);
    for(int i = 1; i <= 9; i++){
        string s;
        cin >> s;
        arr[i] = s.size();
    }

    const int mod = 1e9 + 7;

    vector<long long> dp(10);
    dp[0] = 1;

    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += arr[j] * dp[i - j];
            dp[i] %= mod;
        }
    }

    vector<long long> dp2(10);
    for(int i = 1; i <= 9; i++){
        dp2[i] = (dp2[i - 1] + dp[i]) % mod;
    }

    vector<vector<long long>> v(10, vector<long long>(1));

    v[0][0] = dp2[8];

    for(int i = 1; i <= 9; i++){
        v[i][0] = dp[10 - i];
    }

    vector<vector<long long>> brr(10, vector<long long>(10));

    brr[0][0] = 1;
    brr[0][1] = 1;

    brr[1] = arr;

    for(int i = 2; i <= 9; i++){
        brr[i][i - 1] = 1;
    }

    long long answer = 0;

    if(b > 9){
        auto temp = pow(brr, b - 9, mod);
        auto result = mat_mul(temp, v, mod);
        answer = (result[0][0] + result[1][0]) % mod;
    }else{
        answer = dp2[b];
    }

    if(a > 10){
        auto temp = pow(brr, a - 10, mod);
        auto result = mat_mul(temp, v, mod);
        answer = (answer - (result[0][0] + result[1][0]) % mod + mod) % mod;
    }else{
        answer = (answer - dp2[a - 1] + mod) % mod;
    }

    cout << answer;
    
    return 0;
}