#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> p(n + 1);

    int answer = 0;

    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        cin >> p[a];
        arr[a] = b;
    }

    vector<bool> check(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(2));

    for(int i = 1; i <= n; i++){
        if(!check[i]){
            int now = i;
            int cnt = 0;
            vector<int> result;
            int s = 0;
            while(!check[now]){
                cnt++;
                result.push_back(p[now]);
                s += p[now];
                check[now] = true;
                now = arr[now];
            }
            if(cnt == 1){
                answer += result[0];
            }else if(cnt == 2){
                answer += min(result[0], result[1]);
            }else{
                dp[0][0] = result[0];
                dp[1][0] = result[0];
                for(int j = 2; j < cnt - 1; j++){
                    dp[j][0] = max(dp[j - 2][0] + result[j], dp[j - 1][0]);
                }
                dp[1][1] = result[1];
                for(int j = 2; j < cnt; j++){
                    dp[j][1] = max(dp[j - 2][1] + result[j], dp[j - 1][1]);
                }
                answer += s - max(dp[cnt - 2][0], dp[cnt - 1][1]);
            }
        }
    }

    cout << answer;

    return 0;
}