#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& distance, vector<int>& p, vector<vector<int>>& dp, int now, int visited){

    if(visited == (1 << distance.size()) - 1){
        return distance[now].back();
    }

    int& ret = dp[now][visited];

    if(ret != -1){
        return ret;
    }

    ret = 987654321;

    for(int next = 0; next < distance.size(); next++){
        if(visited & (1 << next)){
            continue;
        }
        if((visited & (1 << p[next])) or p[next] == next){
            ret = min(ret, solve(distance, p, dp, next, visited | (1 << next)) + distance[now][next]);
        }
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        --p[i];
    }
    

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, 987654321));
    
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        --u;
        --v;
        distance[u][v] = min(distance[u][v], c);
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << (n + 1), -1));

    int answer = solve(distance, p, dp, n, 1 << n);

    if(answer == 987654321){
        answer = -1;
    }

    cout << answer;

    return 0;
}