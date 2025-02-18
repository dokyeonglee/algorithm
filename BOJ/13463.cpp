#include <iostream>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& adj, int l, int x){

    vector<int> cnt(adj.size());

    for(int i = 0; i < adj.size(); i++){
        cnt[i] = (adj[i].size() + 1) / 2;
    }
    cnt[l] = 0;

    queue<int> q;
    q.emplace(l);

    vector<int> cnt(adj.size());

    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == x){
            return true;
        }
        for(auto& next : adj[now]){
            if(--cnt[next] == 0){
                q.emplace(next);
            }
        }
    }

    return false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, p, x, l;
    cin >> c >> p >> x >> l;

    vector<vector<int>> adj(c + 1);

    while(p--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    if(bfs(adj, l, x)){
        cout << "leave";
    }else{
        cout << "stay";
    }

    return 0;

}