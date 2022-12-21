#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mul(vector<vector<long long>>& a, vector<vector<long long>>& b, long long mod){
    vector<vector<long long>> result(a.size(), vector<long long>(b[0].size()));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
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
    result = mul(result, result, mod);
    if(n % 2 == 1){
        result = mul(result, arr, mod);
    }
    return result;
}

int main(){

    long long n, m;
    cin >> n >> m;

    long long mod = 1e9 + 7;

    vector<vector<long long>> arr(m, vector<long long>(m));

    arr[0][0] = 1;
    arr[0][m - 1] = 1;

    for(int i = 1; i < m; i++){
        arr[i][i - 1] = 1;
    }
    
    cout << pow(arr, n, mod)[0][0];

    return 0;
}