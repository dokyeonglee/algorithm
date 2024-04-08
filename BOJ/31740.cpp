#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& parent, vector<int>& value, int now, int p){

    for(auto& next : tree[now]){
        if(next != p){
            parent[next] = now;
            value[now] += dfs(tree, parent, value, next, now);
        }
    }

    return value[now];

}

int main(){

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

    vector<int> value(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> value[i];
    }

    vector<int> parent(n + 1);

    dfs(tree, parent, value, 1, -1);

    int diff = 2e9;
    int x = 1;

    for(int i = 1; i <= n; i++){
        if(diff > abs(value[1] - 2 * value[i])){
            diff = abs(value[1] - 2 * value[i]);
            x = i;
        }
    }

    cout << diff << "\n";
    cout << x << " " << parent[x];

    return 0;
}