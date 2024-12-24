#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& adj, vector<int>& observe, int s, int e){    

    int k = observe.size();

    vector<bool> visited(adj.size());
    visited[s] = true;

    queue<pair<int, int>> q;
    q.emplace(s, 0);

    while(!q.empty()){

        int now = q.front().first;
        int t = q.front().second;
        q.pop();

        if(observe[t % k] == now){
            int temp = t;
            while(observe[temp % k] == now){
                temp++;
            }
            q.emplace(now, temp);
            continue;
        }

        if(now == e){
            return t;
        }

        for(auto& next : adj[now]){
            if(!visited[next]){
                visited[next] = true;
                q.emplace(next, t + 1);
            }
        }

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;

    int k;
    cin >> k;

    vector<int> observe(k);
    vector<bool> check(n + 1);

    int cnt = 0;

    for(auto& o : observe){
        cin >> o;
        if(!check[o]){
            cnt++;
            check[o] = true;
        }
    }

    int x = -1;

    if(cnt == 1){
        x = observe[0];
    }

    vector<vector<int>> adj(n + 1);

    while(m--){
        int u, v;
        cin >> u >> v;
        if(u == x or v == x){
            continue;
        }
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    cout << bfs(adj, observe, s, e);

    return 0;
}