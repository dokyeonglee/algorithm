#include <iostream>
#include <queue>

using namespace std;

vector<long long> bfs(vector<vector<int>>& adj, int src){

    vector<long long> distance(adj.size(), 1e18);
    distance[src] = 0;

    queue<int> q;
    q.emplace(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& next : adj[now]){
            if(distance[next] == 1e18){
                distance[next] = distance[now] + 1;
                q.emplace(next);
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;

    vector<vector<int>> adj(n + 1);

    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
    }

    vector<long long> distance = bfs(adj, 1);
    vector<long long> distance2 = bfs(adj, b);

    long long answer = distance[n];

    if(distance[a] != 1e18 and distance2[n] != 1e18){
        if(distance2[a] < c){
            cout << "-inf";
            return 0;
        }
        answer = min(answer, distance[a] + distance2[n] - c);
    }

    if(answer == 1e18){
        cout << 'x';
    }else{
        cout << answer;
    }

    return 0;
}