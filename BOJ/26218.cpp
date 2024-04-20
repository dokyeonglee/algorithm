#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    vector<int> p(n + 1);
    vector<int> a(n + 1);
    vector<int> c(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> p[i] >> a[i] >> c[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(b + 1));
    vector<vector<int>> amount(n + 1, vector<int>(b + 1));

    long long money = 0;

    dp[0][0] = 1;

    long long answer = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= b; j++){
            amount[i][j] = amount[i - 1][j];
            for(int k = 0; k * c[i] <= j; k++){
                long long temp = dp[i - 1][j - k * c[i]] * min(100, p[i] + k * a[i]);
                if(dp[i][j] < temp){
                    dp[i][j] = temp;
                    amount[i][j] = k;
                }
                if(p[i] + k * a[i] > 100){
                    break;
                }
            }
            if(answer < dp[i][j]){
                answer = dp[i][j];
                money = j;
            }
        }
    }

    vector<int> amounts(n + 1);
    cout << answer << "\n";

    for(int i = n; i >= 1; i--){
        amounts[i] = amount[i][money];
        money -= c[i] * amount[i][money];
    }    

    for(int i = 1; i <= n; i++){
        cout << amounts[i] << " ";
    }

    return 0;
}