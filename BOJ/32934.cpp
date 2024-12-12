#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<int>& distance, int now, int p){
    for(auto& next : tree[now]){
        if(next != p){
            distance[next] = distance[now] + 1;
            dfs(tree, distance, next, now);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int d = -1;

    for(int i = 1; i < 20; i++){
        if(3 * (1 << i) - 2 == n){
            d = i;
            break;
        }
    }

    if(d == -1){
        cout << -1;
        return 0;
    }

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    int leaf = -1;

    for(int i = 1; i <= n; i++){
        if(tree[i].size() == 1){
            leaf = i;
        }else if(tree[i].size() != 3){
            cout << -1;
            return 0;
        }
    }

    if(leaf == -1){
        cout << -1;
        return 0;
    }

    vector<int> distance(n + 1);

    dfs(tree, distance, leaf, -1);

    int leaf2 = -1;

    for(int i = 1; i <= n; i++){
        if(distance[i] > 2 * d){
            cout << -1;
            return 0;
        }else if(distance[i] == 2 * d){
            leaf2 = i;
        }
    }

    if(leaf2 == -1){
        cout << -1;
        return 0;
    }

    vector<int> distance2(n + 1);

    dfs(tree, distance2, leaf2, -1);

    int root = -1;

    for(int i = 1; i <= n; i++){
        if(distance2[i] > 2 * d){
            cout << -1;
            return 0;
        }
        if(distance[i] == d and distance2[i] == d){
            root = i;
        }
    }
    
    if(root != -1){
        cout << "1\n";
    }
    
    cout << root;

    return 0;
}