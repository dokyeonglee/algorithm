#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

vector<vector<long long>> matrix_multiplication(vector<vector<long long>>& arr, vector<vector<long long>>& brr){

    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < brr[0].size(); j++){
            for(int k = 0; k < brr.size(); k++){
                result[i][j] += arr[i][k] * brr[k][j] % mod;
            }
            result[i][j] %= mod;
        }
    }

    return result;

}

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n){

    vector<vector<long long>> result(arr.size(), vector<long long>(arr.size()));

    for(int i = 0; i < arr.size(); i++){
        result[i][i] = 1;
    }

    while(n > 0){
        if(n & 1){
            result = matrix_multiplication(result, arr);
        }
        arr = matrix_multiplication(arr, arr);
        n >>= 1;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<long long>> arr(n, vector<long long>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    auto result = pow(arr, k);

    long long answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer += result[i][j];
        }
    }

    answer %= mod;

    cout << answer;

    return 0;

}