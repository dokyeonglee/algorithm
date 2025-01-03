#include <iostream>
#include <queue>

using namespace std;

string bfs(vector<vector<int>>& tree){

    vector<int> is_distance_odd(tree.size(), -1);
    is_distance_odd[0] = 0;

    queue<int> q;
    q.emplace(0);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& next : tree[now]){
            if(is_distance_odd[next] == -1){
                is_distance_odd[next] = (is_distance_odd[now] ^ 1);
                q.emplace(next);
            }
        }
    }

    string result(tree.size() - 1, '0');

    int sz = (tree.size() - 1) % 2;

    for(int i = tree.size() - 1; i > 0; i--){
        result[result.size() - i] += (sz ^ is_distance_odd[i]);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    while(--n){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << bfs(tree);

    return 0;

}