#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1);
    for(int i = 1 ; i <= n; i++){
        cin >> d[i];
    }
    vector<int> arr(1001);

    vector<int> dp(m + 1, -1);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < d[i]; j++){
            cin >> arr[j];    
        }
        for(int j = 0; j < d[i]; j++){
            for(int k = m - arr[j]; k >= 0; k--){
                if(dp[k] >= i - 1){
                    dp[k + arr[j]] = i;
                }
            }
        }
    }

    for(int i = m; i > 0; i--){
        if(dp[i] == n){
            cout << i;
            return 0;
        }
    }

    cout << -1;
    

    return 0;
}