#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> v(1, -1);
    vector<int> v2(1, -1e9);

    vector<int> dp(n);
    vector<int> dp2(n);

    vector<int> arr(n);
    for(int& a : arr){
        cin >> a;
    }

    for(int i = 0; i < n; i++){
        if(v.back() < arr[i]){
            v.push_back(arr[i]);
            dp[i] = v.size() - 1;
        }else{
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            dp[i] = it - v.begin();
            *it = arr[i];
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(v2.back() < -arr[i]){
            v2.push_back(-arr[i]);
            dp2[i] = v2.size() - 1;
        }else{
            auto it = lower_bound(v2.begin(), v2.end(), -arr[i]);
            dp2[i] = it - v2.begin();
            *it = -arr[i];
        }
    }

    for(int i = 0; i < m; i++){
        int q;
        cin >> q;
        q--;
        cout << dp[q] + dp2[q] - 1 << "\n";
    }

    return 0;
}