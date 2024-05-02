#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> height(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> height[i];
        height[i] = -height[i];
    }

    vector<int> score(n + 1);
    vector<int> durability(n + 1);

    for(int i = 2; i <= n; i++){
        cin >> score[i];
    }

    for(int i = 2; i <= n; i++){
        cin >> durability[i];
        durability[i] = -durability[i];
    }

    vector<long long> dp(n + 1);

    for(int i = 2; i <= n; i++){
        auto it = upper_bound(height.begin() + 1, height.begin() + i, height[i] + durability[i]) - 1;
        if(it != height.begin()){
            dp[i] = max(dp[i - 1], dp[it - height.begin()] + score[i]);
        }else{
            dp[i] = dp[i - 1];
        } 
    }

    cout << dp[n];

    return 0;
}