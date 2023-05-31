#include <iostream>
#include <queue>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, vector<bool>& tree, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    sz[x] += sz[y];
    tree[x] = (tree[x] & tree[y]);
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);
    priority_queue<pair<int, int>> pq;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        pq.push(make_pair(1, -i));
    }

    vector<bool> check(n + 1, true);
    vector<bool> tree(n + 1, true);

    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        if(c == 1){
            int u, v;
            cin >> u >> v;
            int pu = find_parent(parent, u);
            int pv = find_parent(parent, v);
            if(pu > pv){
                swap(pu, pv);
            }
            if(pu != pv){
                union_parent(parent, sz, tree, pu, pv);
                pq.push(make_pair(sz[pu], -pu));
            }else{
               tree[pu] = false;
            }
        }else{
            while(!pq.empty() and (!check[find_parent(parent, -pq.top().second)] or !tree[find_parent(parent, -pq.top().second)])){
                pq.pop();
            }
            int p = find_parent(parent, -pq.top().second);
            cout << find_parent(parent, p) << "\n";
            check[p] = false;
            pq.pop();
        }
    }

    return 0;
}