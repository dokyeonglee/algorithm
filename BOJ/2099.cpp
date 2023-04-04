#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mat_mul(vector<vector<int>>& arr, vector<vector<int>>& brr){
    vector<vector<int>> result(arr.size(), vector<int>(brr[0].size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr[0].size(); j++){
            for(int k = 0; k < arr[0].size(); k++){
                result[i][j] |= arr[i][k] & brr[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> pow(vector<vector<int>>& arr, int n){
    if(n == 1){
        return arr;
    }
    auto ret = pow(arr, n / 2);
    ret = mat_mul(ret, ret);
    if(n % 2 == 1){
        ret = mat_mul(ret, arr);
    }   
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<int>> arr(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i][a - 1] = 1;
        arr[i][b - 1] = 1;
    }

    arr = pow(arr, min(n, k));

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(arr[a - 1][b - 1]){
            cout << "death\n";
        }else{
            cout << "life\n";
        }
    }
    
    return 0;
}   