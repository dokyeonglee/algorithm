#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> mat_mul(vector<vector<long long>>& arr, vector<vector<long long>>& brr, long long mod){
    vector<vector<long long>> result(arr.size(), vector<long long>(brr[0].size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < brr[i].size(); j++){
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
    while(n){
        if(n & 1){
            result = mat_mul(arr, result, mod);
        }
        arr = mat_mul(arr, arr, mod);
        n >>= 1;
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> init_alcohol(k);
    for(auto& alcohol : init_alcohol){
        cin >> alcohol;
    }

    int mod;
    cin >> mod;

    long long answer = 0;

    vector<vector<long long>> arr(k, vector<long long>(k));

    fill(arr[0].begin(), arr[0].end(), 1);

    for(int i = 1; i < k; i++){
        arr[i][i - 1] = 1;
    }

    vector<vector<long long>> result = pow(arr, n - k, mod);

    for(int i = 0; i < k; i++){
        answer = (answer + result[0][i] * init_alcohol[k - 1 - i]) % mod;
    }

    cout << answer;

    return 0;
}