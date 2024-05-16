#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int solve(vector<vector<pair<int, int>>>& adj, vector<vector<int>>& answer, int src, int dst){
    
    if(answer[src][dst] != -1){
        return answer[src][dst];
    }

    vector<bool> visited(adj.size());
    visited[src] = true;

    queue<pair<int, int>> q;
    q.emplace(src, 1e9);

    while(!q.empty()){

        int now = q.front().first;
        int width = q.front().second;
        q.pop();

        if(now == dst){
            return width;
        }

        for(auto& e : adj[now]){

            int next = e.first;

            if(!visited[next]){
                visited[next] = true;
                answer[src][next] = min(width, e.second);
                answer[next][src] = answer[src][next];
                q.emplace(next, min(width, e.second));
            }

        }

    }

    return -1;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, pair<int, int>>> edges(m);

    for(auto& e : edges){
        cin >> e.second.first >> e.second.second >> e.first;
    }

    sort(edges.begin(), edges.end(), greater<>());

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<vector<pair<int, int>>> adj(n + 1);

    for(auto e : edges){

        int width = e.first;
        int u = e.second.first;
        int v = e.second.second;

        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, u, v);
            adj[u].emplace_back(v, width);
            adj[v].emplace_back(u, width);
        }

    }

    vector<vector<int>> answer(n + 1, vector<int>(n + 1, -1));

    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        cout << solve(adj, answer, u, v) << "\n";
    }

    return 0;
}