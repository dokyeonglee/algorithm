#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> dp(101, vector<int>(101));

    const int mod = 1e9 + 7;

    for(int i = 0; i <= 100; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 2);

    int s = 1;
    int e = n;

    int idx = s + (e - s) / 2;
    int x;

    cin >> arr[idx];

    for(int i = 1; i < k; i++){
        cin >> x;
        if(arr[idx] < x){
            s = idx + 1;
        }else{
            e = idx - 1;
        }
        idx = s + (e - s) / 2;
        arr[idx] = x;
    }

    arr[n + 1] = 101;

    idx = 1;
    x = 1;

    long long answer = 1;

    for(int i = 1; i <= n + 1; i++){
        if(arr[i]){
            answer = answer * dp[arr[i] - x][i - idx] % mod;
            idx = i + 1;
            x = arr[i] + 1;
        }
    }

    cout << answer;

    return 0;
}