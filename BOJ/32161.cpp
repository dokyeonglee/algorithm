#include <iostream>
#include <queue>
#include <map>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

void bfs(vector<vector<int>>& adj, vector<vector<int>>& distance, int src){

    distance[src][src] = 0;

    queue<int> q;
    q.emplace(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            if(distance[src][next] == -1){
                distance[src][next] = distance[src][now] + 1;
                q.emplace(next);
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    map<int, int> node_num_map;

    vector<int> parent(2 * m + 1);
    vector<int> sz(2 * m + 1, 1);
    vector<vector<int>> adj(2 * m + 1);
    vector<vector<int>> distance(2 * m + 1, vector<int>(2 * m + 1, -1));

    for(int i = 1; i < parent.size(); i++){
        parent[i] = i;
    }

    int cnt = 0;

    int u, v;

    while(m--){
        cin >> u >> v;
        if(node_num_map.count(u) == 0){
            node_num_map[u] = ++cnt;
        }
        if(node_num_map.count(v) == 0){
            node_num_map[v] = ++cnt;
        }
        u = node_num_map[u];
        v = node_num_map[v];
        adj[u].push_back(v);
        adj[v].push_back(u);
        union_parent(parent, sz, u, v);
    }

    for(int i = 1; i <= cnt; i++){
        bfs(adj, distance, i);
    }

    while(q--){
        cin >> u >> v;
        if(u == v){
            cout << "0\n";
        }else if(node_num_map.count(u) == 0 or node_num_map.count(v) == 0){
            cout << "1\n";
        }else{

            u = node_num_map[u];
            v = node_num_map[v];

            if(distance[u][v] == -1){
                cout << "1\n";
            }else if(distance[u][v] < 3 or sz[find_parent(parent, u)] == n){
                cout << distance[u][v] << "\n";
            }else{
                cout << "2\n";
            }

        }
    }

    return 0;
}