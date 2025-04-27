#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& color, int now, int c){
    color[now] = c;
    for(auto& next : adj[now]){
        if(color[next] == c){
            return false;
        }
        if(color[next] == -1){
            if(!dfs(adj, color, next, c ^ 1)){
                return false;
            }
        }
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n + 1);

    vector<pair<int, int>> edges(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> arr(k);
    vector<bool> check(m + 1);
    for(int i = 0; i < k; i++){
        cin >> arr[i];
        check[arr[i]] = true;
    }

    for(int i = 1; i <= m; i++){
        if(!check[i]){
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    vector<int> color(n + 1, -1);

    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!dfs(adj, color, i, 0)){
                cout << -1;
                return 0;
            }
        }
    }

    int answer = 0;

    for(int i = k - 1; i >= 0; i--){
        int u = edges[arr[i]].first;
        int v = edges[arr[i]].second;
        if(color[u] == color[v]){
            answer = i + 1;
            break;
        }
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        cnt += color[i];
    }

    if(cnt > n - cnt){
        cnt = n - cnt;
    }

    cout << answer << "\n";
    cout << cnt << " " << n - cnt;

    return 0;

}