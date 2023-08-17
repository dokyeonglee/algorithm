#include <iostream>
#include <vector>

using namespace std;

int parent[100001][18];
int min_length[100001][18];
int max_length[100001][18];
int depth[100001];
bool visited[100001];

void dfs(vector<vector<pair<int, int>>>& tree, int now, int d, int p){

    visited[now] = true;
    depth[now] = d;

    for(auto& e : tree[now]){
        int next = e.first;
        int cost = e.second;
        if(!visited[next]){
            parent[next][0] = now;
            min_length[next][0] = cost;
            max_length[next][0] = cost;
            dfs(tree, next, d + 1, p + cost);
        }
    }

}

void lca(int u, int v){

    int _min = 1e9;
    int _max = 0;

    if(depth[u] > depth[v]){
        swap(u, v);
    }

    for(int i = 17; i >= 0; i--){
        if(depth[v] - depth[u] >= (1 << i)){
            _min = min(_min, min_length[v][i]);
            _max = max(_max, max_length[v][i]);
            v = parent[v][i];
        }
    }

    if(u == v){
        cout << _min << " " << _max << "\n";
        return;
    }

    for(int i = 17; i >= 0; i--){
        if(parent[u][i] != parent[v][i]){
            _min = min(_min, min(min_length[u][i], min_length[v][i]));
            _max = max(_max, max(max_length[u][i], max_length[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    _min = min(_min, min(min_length[u][0], min_length[v][0]));
    _max = max(_max, max(max_length[u][0], max_length[v][0]));

    cout << _min << " " << _max << "\n";

    return;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

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
            min_length[j][i] = min(min_length[j][i - 1], min_length[parent[j][i - 1]][i - 1]);
            max_length[j][i] = max(max_length[j][i - 1], max_length[parent[j][i - 1]][i - 1]);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int u, v;
        cin >> u >> v;
        lca(u, v); 
    }

    return 0;
}