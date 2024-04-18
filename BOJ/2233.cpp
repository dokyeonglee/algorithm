#include <iostream>
#include <vector>

using namespace std;

int get_lca(vector<vector<int>>& parent, vector<int>& depth, int u, int v){

    if(depth[u] > depth[v]){
        swap(u, v);
    }

    for(int i = 11; i >= 0; i--){
        if(depth[v] - depth[u] >= (1 << i)){
            v = parent[v][i];
        }
    }

    if(u == v){
        return u;
    }

    for(int i = 11; i >= 0; i--){
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

    int n;
    cin >> n;

    string str;
    cin >> str;

    int x, y;
    cin >> x >> y;

    int idx = 1;
    int now = 0;

    vector<int> node_index(str.size());
    vector<vector<int>> parent(n + 1, vector<int>(12));
    vector<int> depth(n + 1);

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '0'){
            parent[idx][0] = now;
            depth[idx] = depth[now] + 1;
            node_index[i] = idx;
            now = idx++;
        }else{
            node_index[i] = now;
            now = parent[now][0];
        }
    }

    for(int j = 1; j <= 11; j++){
        for(int i = 1; i <= n; i++){
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    int lca = get_lca(parent, depth, node_index[x - 1], node_index[y - 1]);

    for(int i = 0; i < str.size(); i++){
        if(node_index[i] == lca){
            cout << i + 1 << " ";
        }
    }

    return 0;
}