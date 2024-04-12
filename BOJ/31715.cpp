#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    const int mod = 1e9 + 7;

    long long answer = 1;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            arr[i][j] += d * i;
        }
    }

    for(int i = 0; i < n; i++){
        sort(arr[i].begin(), arr[i].end());
    }

    for(int i = 1; i < n; i++){
        int idx = 0;
        long long result = 1;
        for(int j = 0; j < m; j++){
            while(idx < m and arr[i - 1][idx] < arr[i][j]){
                idx++;
            }
            if(idx < j){
                cout << 0;
                return 0;
            }else{
                result = result * (idx - j) % mod;
            }
        }
        answer = (answer * result) % mod;
    }

    for(int i = 2; i <= m; i++){
        answer = answer * i % mod;
    }

    cout << answer;

    return 0;
}