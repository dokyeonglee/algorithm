#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, cheese_burger, french_fries;
    cin >> n >> cheese_burger >> french_fries;

    vector<pair<int, int>> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<vector<int>> dp(cheese_burger + 1, vector<int>(french_fries + 1));

    for(int i = 1; i <= n; i++){
        int x = arr[i].first;
        int y = arr[i].second;
        for(int j = cheese_burger; j >= x; j--){
            for(int k = french_fries; k >= y; k--){
                dp[j][k] = max(dp[j][k], dp[j - x][k - y] + 1);
            }
        }
    }

    cout << dp[cheese_burger][french_fries];

    return 0;

}