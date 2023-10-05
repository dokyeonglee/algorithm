#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
    for(int k = 0; k < brr.size(); k++){
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < brr[0].size(); j++){
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

    if(n % 2){
        result = mat_mul(result, arr, mod);
    }

    return result;

}

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

    const int mod = 1e8 + 7;

    int t;
    cin >> t;

    while(t--){

        long long k, n;
        cin >> k >> n;

        if(n <= k){
            cout << "1\n";
            continue;
        }

        if(k == 0){
            cout << pow(2, n, mod) << "\n";
            continue;
        }

        vector<vector<long long>> arr(k + 1, vector<long long>(k + 1));

        arr[0][0] = 1;
        arr[0][k] = 1;
        for(int i = 1; i <= k; i++){
            arr[i][i - 1] = 1;
        }

        auto result = pow(arr, n - k, mod);
        
        long long answer = 0;
        for(int i = 0; i <= k; i++){
            answer = (answer + result[0][i]) % mod;
        }

        cout << answer << "\n";

    }

    return 0;
}