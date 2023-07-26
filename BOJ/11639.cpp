#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& dp, vector<int>& t, vector<int>& d, vector<vector<int>>& dist, int now, int visited, int limit){
    int n = dp.size();
    int& ret = dp[now][visited];
    if(ret != -1){
        return ret;
    }
    if(visited == (1 << now)){
        int result = dist[n][now] + t[now];
        return ret = (result > d[now] ? limit: result);
    }
    ret = limit;
    for(int i = 0; i < n; i++){
        if(i == now) continue;
        if((visited & (1 << i))){
            int result = solve(dp, t, d, dist, i, visited ^ (1 << now), limit) + t[now] + dist[i][now];
            if(result > d[now]) continue;
            ret = min(ret, result);
        }
    }
    
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    vector<int> p(n + 5);
    vector<int> t(n + 5);
    vector<int> d(n + 5);

    for(int i = 0; i < n; i++){
        cin >> p[i] >> t[i] >> d[i];
        if(d[i] == -1){
            d[i] = T;
        }
    }

    vector<int> s(1 << n);
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                s[i] += p[j];
            }
        }
    }

    vector<vector<int>> dist(n + 2, vector<int>(n + 2));
    for(int i = 0; i < n + 2; i++){
        for(int j = 0; j < n + 2; j++){
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int answer = 0;
    int bit = 0;

    for(int j = 0; j < (1 << n); j++){
        if(answer > s[j]){
            continue;
        }
        for(int i = 0; i < n; i++){
            if(!(j & (1 << i))){
                continue;
            }
            if(solve(dp, t, d, dist, i, j, T) + dist[i][n + 1] <= T){
                if(answer < s[j]){
                    answer = s[j];
                    bit = j;
                }else if(answer == s[j]){
                    int result = (bit ^ j);
                    if((result & -result) & j){
                        bit = j;
                    }
                }
            }
        }
    }

    cout << answer << "\n";
    for(int i = 0; i < n; i++){
        if(bit & (1 << i)){
            cout << i + 1 << " ";
        }
    }

    return 0;
}