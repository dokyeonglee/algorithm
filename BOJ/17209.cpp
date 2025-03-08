#include <iostream>
#include <vector>

using namespace std;

pair<int, int> dfs(vector<vector<int>>& adj, vector<bool>& visited, int now, bool is_newbie){
    pair<int, int> result(is_newbie, !is_newbie);
    visited[now] = true;
    for(int& next : adj[now]){
        if(!visited[next]){
            auto p = dfs(adj, visited, next, !is_newbie);
            result.first += p.first;
            result.second += p.second;
        }
    }
    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < n; j++){
            if(str[j] == '1'){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n);

    int answer = 0;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            auto p = dfs(adj, visited, i, true);
            answer += max(p.first, p.second);
        }
    }

    cout << answer;

    return 0;

}