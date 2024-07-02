#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
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

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n, long long mod){
    if(n == 0){
        vector<vector<long long>> result(arr.size(), vector<long long>(arr.size()));
        for(int i = 0; i < arr.size(); i++){
            result[i][i] = 1;
        }
        return result;
    }
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

    int t, n, d;
    cin >> t >> n >> d;

    const long long mod = 1e9 + 7;

    vector<vector<long long>> arr(n, vector<long long>(n));
    vector<vector<long long>> answer(arr);

    for(int i = 0; i < n; i++){
        answer[i][i] = 1;
    }

    long long m;
    cin >> m;

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        arr[--u][--v] = c;
    }

    for(int i = 1; i < t; i++){
        vector<vector<long long>> temp(n, vector<long long>(n));
        cin >> m;
        if(d % t == i){
            answer = arr;
        }
        while(m--){
            int u, v, c;
            cin >> u >> v >> c;
            temp[--u][--v] = c;
        }
        arr = mat_mul(arr, temp, mod);
    }

    arr = pow(arr, d / t, mod);
    answer = mat_mul(arr, answer, mod);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}