#include <iostream>
#include <vector>

using namespace std;

int parent[100001][18];
int price[100001];
int depth[100001];
bool visited[100001];

void dfs(vector<vector<pair<int, int>>>& tree, int now, int d, int p){

    visited[now] = true;
    depth[now] = d;
    price[now] = p;

    for(auto& e : tree[now]){
        int next = e.first;
        int cost = e.second;
        if(!visited[next]){
            parent[next][0] = now;
            dfs(tree, next, d + 1, p + cost);
        }
    }

}

int lca(int u, int v){

    if(depth[u] > depth[v]){
        swap(u, v);
    }

    for(int i = 17; i >= 0; i--){
        if(depth[v] - depth[u] >= (1 << i)){
            v = parent[v][i];
        }
    }

    if(u == v){
        return u;
    }

    for(int i = 17; i >= 0; i--){
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

    int n, q;
    cin >> n >> q;

    vector<vector<pair<int, int>>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        tree[u].push_back(make_pair(v, c));
        tree[v].push_back(make_pair(u, c));
    }

    dfs(tree, 1, 0, 0);

    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        cout << price[u] + price[v] - 2 * price[lca(u, v)] << "\n";
    }

    return 0;
}