#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    vector<int> a(m + 1);
    vector<int> b(m + 1);
    vector<int> c(m + 1);
    vector<int> d(m + 1);

    for(int i = 1; i <= m; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> dp(n + 1);

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < a[i] / b[i]; j++){
            for(int k = n; k >= c[i]; k--){
                dp[k] = max(dp[k], dp[k - c[i]] + d[i]);
            }
        }
    }

    int answer = dp[n];

    for(int i = 1; i <= n / c0; i++){
        answer = max(answer, dp[n - i * c0] + i * d0);
    }

    cout << answer;

    return 0;
}