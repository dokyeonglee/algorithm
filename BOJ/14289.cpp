#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
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

vector<vector<long long>> pow(vector<vector<long long>>& arr, long long n, long long mod){

    vector<vector<long long>> result(arr.size(), vector<long long>(arr[0].size()));

    for(int i = 0; i < arr.size(); i++){
        result[i][i] = 1;
    }

    auto temp = arr;

    while(n){
        if(n % 2){
            result = mat_mul(result, temp, mod);
        }
        temp = mat_mul(temp, temp, mod);
        n /= 2;
    }

    return result;
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> arr(n, vector<long long>(n));

    while(m--){
        long long u, v;
        cin >> u >> v;
        --u;
        --v;
        arr[u][v] = 1;
        arr[v][u] = 1;    
    }

    const long long mod = 1e9 + 7;

    long long d;
    cin >> d;

    auto answer = pow(arr, d, mod);

    cout << answer[0][0];

    return 0;
}