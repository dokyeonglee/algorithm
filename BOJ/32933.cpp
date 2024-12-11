#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> dp(m + 1);

    while(k--){
        int a, b, c;
        cin >> a >> b >> c;
        b = min(a, b);
        for(int i = 1; a + (i - 1) * b <= m; i++){
            for(int j = m; j >= a + (i - 1) * b; j--){
                dp[j] = max(dp[j], dp[j - a - (i - 1) * b] + c * i);
            }
        }
    }

    cout << dp[m] * n;

    return 0;
}