#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
    vector<vector<long long>> result(arr.size(), vector<long long>(brr.size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
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
    auto ret = pow(arr, n / 2, mod);
    ret = mat_mul(ret, ret, mod);
    if(n % 2 == 1){
        ret = mat_mul(ret, arr, mod);
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<long long>> arr(8, vector<long long>(8));
    arr[0][1] = 1;
    arr[0][2] = 1;
    arr[1][0] = 1;
    arr[1][2] = 1;
    arr[1][3] = 1;
    arr[2][0] = 1;
    arr[2][1] = 1;
    arr[2][3] = 1;
    arr[2][4] = 1;
    arr[3][1] = 1;
    arr[3][2] = 1;
    arr[3][4] = 1;
    arr[3][5] = 1;
    arr[4][2] = 1;
    arr[4][3] = 1;
    arr[4][5] = 1;
    arr[4][7] = 1;
    arr[5][3] = 1;
    arr[5][4] = 1;
    arr[5][6] = 1;
    arr[6][5] = 1;
    arr[6][7] = 1;
    arr[7][6] = 1;
    arr[7][4] = 1;

    int d;
    cin >> d;

    cout << pow(arr, d, 1e9 + 7)[0][0];

    return 0;
}