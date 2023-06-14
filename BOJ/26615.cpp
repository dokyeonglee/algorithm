#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& parent, vector<bool>& visited, vector<int>& depth, int now, int d){
    visited[now] = true;
    depth[now] = d;
    for(int next : graph[now]){
        if(visited[next]){
            continue;
        }
        parent[next][0] = now;
        dfs(graph, parent, visited, depth, next, d + 1);
    }
}

int lca(vector<vector<int>>& graph, vector<vector<int>>& parent, vector<int>& depth, int u, int v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for(int i = 0; diff; i++){
        if(diff & 1){
            u = parent[u][i];
        }
        diff >>= 1;
    }
    if(u == v){
        return u;
    }
    for(int i = 20; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> graph(n * m + 1);

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x == 0){
                graph[i * m + j].push_back((i + 1) * m + j);
                graph[(i + 1) * m + j].push_back(i * m + j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            int x;
            cin >> x;
            if(x == 0){
                graph[i * m + j].push_back(i * m + j + 1);
                graph[i * m + j + 1].push_back(i * m + j);
            }
        }
    }

    vector<vector<int>> parent(n * m + 1, vector<int>(21));
    vector<bool> visited(n * m + 1);
    vector<int> depth(n * m + 1);

    dfs(graph, parent, visited, depth, 0, 0);
    
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n * m; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    int k;
    cin >> k;

    vector<long long> psum(t + 5);

    while(k--){
        int s, e, a, b, c, d, v;
        cin >> s >> e >> a >> b >> c >> d >> v;
        int x = a * m + b;
        int y = c * m + d;
        int p = lca(graph, parent, depth, x, y);
        int q = (depth[x] - depth[p] + depth[y] - depth[p] + 1) * v;
        psum[s] += q;
        psum[e + 1] -= q;
    }

    for(int i = 1; i <= t; i++){
        psum[i] += psum[i - 1];
    }

    for(int i = 1; i <= t; i++){
        cout << psum[i] << "\n";
    }

    return 0;
}