#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& disjoint_set_parent, int x){
    if(disjoint_set_parent[x] == x){
        return x;
    }
    return disjoint_set_parent[x] = find_parent(disjoint_set_parent, disjoint_set_parent[x]);
}

void union_parent(vector<int>& disjoint_set_parent, vector<int>& sz, int x, int y){
    x = find_parent(disjoint_set_parent, x);
    y = find_parent(disjoint_set_parent, y);
    if(x != y){
        sz[x] += sz[y];
        disjoint_set_parent[y] = x;
    }
}

void dfs(vector<vector<int>>& tree, vector<int>& tree_parent, int now, int p){

    for(int next : tree[now]){
        if(next != p){
            tree_parent[next] = now;
            dfs(tree, tree_parent, next, now);
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> disjoint_set_parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        disjoint_set_parent[i] = i;
    }

    vector<int> tree_parent(n + 1);

    dfs(tree, tree_parent, 1, 0);

    int q;
    cin >> q;

    vector<bool> check(n + 1);

    while(q--){

        int k;
        cin >> k;

        vector<int> s(k);
        for(int i = 0; i < k; i++){
            cin >> s[i];
            check[s[i]] = true;
        }

        for(int i = 0; i < k; i++){
            if(check[tree_parent[s[i]]]){
                union_parent(disjoint_set_parent, sz, s[i], tree_parent[s[i]]);
            }
        }

        long long answer = 0;

        for(int i = 0; i < k; i++){
            if(find_parent(disjoint_set_parent, s[i]) == s[i]){
                answer += (long long)sz[s[i]] * (sz[s[i]] - 1) / 2;
            }
            check[s[i]] = false;
            disjoint_set_parent[s[i]] = s[i];
            sz[s[i]] = 1;
        }

        cout << answer << "\n";

    }

    return 0;
}