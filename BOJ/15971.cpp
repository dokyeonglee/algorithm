#include <iostream>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<pair<int, int>>>& graph, int src){

    vector<int> distance(graph.size(), 1987654321);
    distance[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto e : graph[now]){
            int next = e.first;
            int dist = e.second;
            if(distance[next] == 1987654321){
                distance[next] = distance[now] + dist;
                q.push(next);
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, robot1, robot2;
    cin >> n >> robot1 >> robot2;

    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 1; i < n; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
        graph[v].push_back(make_pair(u, c));
    }

    vector<int> distance = bfs(graph, robot1);
    vector<int> distance2 = bfs(graph, robot2);

    int answer = 1987654321;

    for(int i = 1; i <= n; i++){
        answer = min(answer, distance[i] + distance2[i]);
        for(int j = 0; j < graph[i].size(); j++){
            answer = min(answer, distance[i] + distance2[graph[i][j].first]);
        }       
    }

    cout << answer;

    return 0;
}