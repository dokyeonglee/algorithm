#include <iostream>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& src){

    vector<int> distance(graph.size(), 987654321);
    
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < src.size(); i++){
        distance[src[i]] = 0;
        pq.push(make_pair(0, src[i]));
    }

    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto e : graph[now]){
            int next = e.first;
            int cost = e.second + dist;
            if(distance[next] > cost){
                distance[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }

    return distance;

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
        graph[v].push_back(make_pair(u, c));
    }

    int number_of_mcdonalds, x;
    cin >> number_of_mcdonalds >> x;

    vector<int> mcdonalds(number_of_mcdonalds);
    for(int i = 0; i < number_of_mcdonalds; i++){
        cin >> mcdonalds[i];
    }

    int number_of_starbucks, y;
    cin >> number_of_starbucks >> y;

    vector<int> starbucks(number_of_starbucks);
    for(int i = 0; i < number_of_starbucks; i++){
        cin >> starbucks[i];       
    }

    vector<int> mcdonalds_distance = dijkstra(graph, mcdonalds);
    vector<int> starbucks_distance = dijkstra(graph, starbucks);

    int answer = 987654321;
    for(int i = 1; i <= n; i++){
        if(mcdonalds_distance[i] > 0 and mcdonalds_distance[i] <= x and starbucks_distance[i] > 0 and starbucks_distance[i] <= y){
            answer = min(answer, mcdonalds_distance[i] + starbucks_distance[i]);
        }
    }

    if(answer == 987654321){
        answer = -1;
    }

    cout << answer;

    return 0;
}