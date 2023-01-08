#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool reachable(vector<vector<pair<int, int>>>& graph, int src, int dst){

    vector<bool> visited(graph.size());
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto e : graph[now]){
            if(!visited[e.first]){
                visited[e.first] = true;
                q.push(e.first);
            }
        }
    }

    return visited[dst];
    
}

vector<int> bellman_ford(vector<vector<pair<int, int>>>& graph){

    int n = graph.size() - 1;

    vector<int> distance(n + 1, -1e9);
    distance[1] = 0;
    
    vector<int> predecessor(n + 1, -1);

    for(int i = 1; i <= n; i++){
        for(int now = 1; now <= n; now++){
            for(auto e : graph[now]){
                int next = e.first;
                int dist = e.second;
                if(distance[now] != -1e9 and distance[next] < distance[now] + dist){
                    distance[next] = distance[now] + dist;
                    predecessor[next] = now;
                    if(i == n){
                        if(reachable(graph, now, n)){
                            distance[n] = -1e9;
                            break;
                        }
                    }
                }
            }
        }
    }

    if(distance[n] == -1e9){
        return {-1};
    }

    vector<int> result;

    int u = n;

    while(u != -1){
        result.push_back(u);
        u = predecessor[u];
    }

    reverse(result.begin(), result.end());

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
    }

    vector<int> answer = bellman_ford(graph);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}