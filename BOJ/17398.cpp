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
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, int>> edges(m);
    for(auto& edge : edges){
        cin >> edge.first >> edge.second;
    }

    vector<bool> check(m);

    vector<int> queries(q);
    for(auto& query : queries){
        cin >> query;
        check[query - 1] = true;
    }

    for(int i = 0; i < m; i++){
        if(!check[i]){
            int pu = find_parent(parent, edges[i].first);
            int pv = find_parent(parent, edges[i].second);
            if(pu != pv){ 
                union_parent(parent, sz, pu, pv);
            }
        }
    }

    long long answer = 0;

    for(int i = q - 1; i >= 0; i--){
        int idx = queries[i] - 1;
        int pu = find_parent(parent, edges[idx].first);
        int pv = find_parent(parent, edges[idx].second);
        if(pu != pv){
            answer += 1ll * sz[pu] * sz[pv];
            union_parent(parent, sz, pu, pv);
        }
    }

    cout << answer;

    return 0;
}