#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& target_color, vector<bool>& visited, int now, int color){

    visited[now] = true;

    int result = (target_color[now] != color);

    for(int next : tree[now]){
        if(!visited[next]){
            result += dfs(tree, target_color, visited, next, target_color[now]);
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> target_color(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> target_color[i];
    }

    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<bool> visited(n + 1);

    cout << dfs(tree, target_color, visited, 1, 0);

    return 0;
}