#include <iostream>
#include <queue>

using namespace std;

int topology_sort(vector<vector<int>>& adj, vector<int> in_degree, string& str){

    queue<int> q;

    for(int i = 0; i < adj.size(); i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> dp(adj.size(), 1);

    int result = 0;

    for(int i = 0; i < adj.size(); i++){
        if(q.empty()){
            return -1;
        }
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            dp[next] = max(dp[next], dp[now] + 1);
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < adj.size(); i++){
        if(str[i] == 'H'){
            result = max(result, dp[i] / 3 * 3);
        }
    }

    if(result == 0){
        result = -1;
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string str;
    cin >> str;

    vector<vector<int>> adj(n);
    vector<int> in_degree(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if(str[u] == str[v]){
            continue;
        }
        if(str[v] == 'K' and str[u] == 'D'){
            swap(u, v);
        }
        if(str[v] == 'D' and str[u] == 'H'){
            swap(u, v);
        }
        if(str[v] == 'H' and str[u] == 'K'){
            swap(u, v);
        }
        adj[u].push_back(v);
        in_degree[v]++;
    }

    cout << topology_sort(adj, in_degree, str);   

    return 0;
}