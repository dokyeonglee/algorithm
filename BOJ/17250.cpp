#include <iostream>
#include <vector>

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
    parent[y] = x;
    sz[x] += sz[y];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        cin >> sz[i];
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, sz, u, v);
        }
        cout << sz[find_parent(parent, u)] << "\n";
    }

    

    return 0;
}