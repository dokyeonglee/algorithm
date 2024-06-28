#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, int mod){
    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < brr[0].size(); j++){
            for(int k = 0; k < brr.size(); k++){
                result[i][j] += arr[i][k] * brr[k][j];
                result[i][j] %= mod;
            }
        }
    }
    return result;
}

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n, int mod){
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

    const int mod = 1e9;

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;
        vector<vector<long long>> fib(2, vector<long long>(2, 1));
        fib[1][1] = 0;
        fib = pow(fib, n, mod);
        cout << fib[0][1] << "\n";
    }

    return 0;
}