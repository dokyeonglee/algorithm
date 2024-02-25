#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
    for(int k = 0; k < arr[0].size(); k++){
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < brr[0].size(); j++){
                result[i][j] += arr[i][k] * brr[k][j] % mod;
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
    if(n % 2){
        result = mat_mul(result, arr, mod);
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if(n == 1){
        cout << 3;
        return 0;
    }

    const int mod = 1e9 + 7;

    vector<vector<long long>> arr = {{0, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    vector<vector<long long>> result = pow(arr, n - 1, mod);

    vector<vector<long long>> temp = {{1}, {1}, {1}};
    result = mat_mul(result, temp, mod);

    cout << (result[0][0] + result[1][0] + result[2][0]) % mod;

    return 0;
}