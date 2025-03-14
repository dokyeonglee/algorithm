#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<vector<int>>& team, int now, int team_number){
    visited[now] = true;
    team[team_number].push_back(now);
    for(int& next : adj[now]){
        if(!visited[next]){
            dfs(adj, visited, team, next, team_number ^ 1);
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        adj[i].resize(m);
        for(auto& x : adj[i]){
            cin >> x;
        }
    }

    vector<vector<int>> team(2);

    vector<bool> visited(n + 1);

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(adj, visited, team, i, 0);
        }
    }

    sort(team[0].begin(), team[0].end());
    sort(team[1].begin(), team[1].end());

    cout << team[0].size() << "\n";
    for(auto& x : team[0]){
        cout << x << " ";
    }

    cout << "\n";

    cout << team[1].size() << "\n";
    for(auto& x : team[1]){
        cout << x << " ";
    }

    return 0;

}