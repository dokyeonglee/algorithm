#include <iostream>
#include <queue>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<bool>& visited, int now, int p, int x){
    for(int& next : tree[now]){
        if(next != p){
            if(next == x){
                visited[now] = true;
                return;
            }
            dfs(tree, visited, next, now, x);
        }
    }
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

    int a, b, x;
    cin >> a >> b >> x;

    vector<bool> visited(n + 1);

    dfs(tree, visited, a, -1, x);
    dfs(tree, visited, b, -1, x);

    queue<int> q;
    q.push(x);

    visited[x] = true;

    int answer = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer++;
        for(auto& next : tree[now]){
            if(!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }

    cout << answer;

    return 0;
}