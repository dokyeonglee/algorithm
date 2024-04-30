#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> t(n + 1);
    vector<int> b(n + 1);
    vector<int> c(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    vector<long long> dp(n + 1);
    vector<long long> dp2(n + 1);

    for(int i = 1; i <= n; i++){
        auto it = lower_bound(t.begin() + 1, t.end(), t[i] - b[i]) - t.begin(); 
        dp[i] = dp2[it - 1] + c[i];
        dp2[i] = max(dp2[i - 1], dp[i]);
    }

    cout << dp2[n];

    return 0;
}