#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, vector<int>& male, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        male[x] += male[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);
    vector<int> male(n + 1);
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 1; i <= n; i++){
        cin >> male[i];
        male[i] %= 2;
    }

    long long result = 0;

    while(m--){
        int u, v;
        cin >> u >> v;
        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);
        if(pu != pv){
            result += 1ll * (sz[pu] - male[pu]) * male[pv] + 1ll * (sz[pv] - male[pv]) * male[pu];
            union_parent(parent, sz, male, pu, pv);
        }
        cout << result << "\n";
    }

    return 0;
}