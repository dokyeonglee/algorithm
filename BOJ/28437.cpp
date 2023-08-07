#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;


    vector<int> arr(n);
    vector<int> dp(1e5 + 1);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    
    for(int i = 1; i <= 1e5; i++){
        for(int j = 2 * i; j <= 1e5; j += i){
            dp[j] += dp[i];
        }
    }

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        cout << dp[x] << " ";
    }

    return 0;
}