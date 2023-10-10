#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<int> w(n + 1);
    vector<int> t(n + 1);
    vector<int> p(n + 1);

    int sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> w[i];
        sum += w[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    if(sum < s){
        cout << -1;
        return 0;
    }

    vector<vector<int>> arr(n + 1);

    for(int i = 1; i <= n; i++){
        if(p[i] == 0){
            arr[i].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        int temp = i;
        while(p[temp]){
            temp = p[temp];
        }
        if(p[i]){
            w[i] += w[arr[temp].back()];
            t[i] += t[arr[temp].back()];
            arr[temp].push_back(i);
        }
    }

    vector<int> dp(sum + 1, 987654321);
    dp[0] = 0;

    for(int j = 1; j <= n; j++){
        if(p[j] == 0){
            for(int i = sum; i >= w[j]; i--){
                for(int k = 0; k < arr[j].size(); k++){
                    if(i >= w[arr[j][k]]){
                        dp[i] = min(dp[i], dp[i - w[arr[j][k]]] + t[arr[j][k]]);
                    }
                }
            }
        }
    }

    int answer = 987654321;

    for(int i = s; i <= sum; i++){
        answer = min(answer, dp[i]);
    }

    cout << answer;

    return 0;
}