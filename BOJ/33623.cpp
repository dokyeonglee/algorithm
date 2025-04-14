#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& adj, vector<vector<bool>>& wormhole, int o, int s, int e){

    vector<vector<bool>> visited(o + 1, vector<bool>(adj.size()));
    visited[1][s] = true;

    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, make_pair(1, s));    

    while(!q.empty()){
        int dist = q.front().first;
        int k = q.front().second.first;
        int now = q.front().second.second;
        q.pop();
        if(now == e and k == o){
            return dist;
        }
        if(wormhole[k][now]){
            visited[k + 1][now] = true;
            q.emplace(dist, make_pair(k + 1, now));
        }
        for(int& next : adj[now]){
            if(!visited[k][next]){
                visited[k][next] = true;
                q.emplace(dist + 1, make_pair(k, next));
            }
        }
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, o, s, e;
    cin >> n >> o >> s >> e;

    vector<vector<int>> adj(n + 1);

    int m;
    cin >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<bool>> wormhole(o + 1, vector<bool>(n + 1));

    int p;
    cin >> p;

    while(p--){
        int w, x;
        cin >> w >> x;
        wormhole[w][x] = true;
    }

    int answer = bfs(adj, wormhole, o, s, e);

    int q;
    cin >> q;

    while(q--){
        int a, b;
        cin >> a >> b;
        if(answer == -1){
            cout << "-1\n";
        }else{
            cout << a * answer + b * (o - 1) << "\n";
        }
    }

    return 0;

}