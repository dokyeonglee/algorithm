#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src){
	
	vector<int> distance(graph.size(), INF);
	distance[src] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(pair<int, int> e : graph[now]){
			
			int next = e.first;
			int cost = e.second + dist;
			
			if(distance[next] > cost){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
			}
			
		}
		
	}
	
	return distance;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, e;
	cin >> n >> e;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < e; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	int v1, v2;
	cin >> v1 >> v2;
	
	vector<int> distance = dijkstra(graph, 1);
	vector<int> distance_v1 = dijkstra(graph, v1);
	vector<int> distance_v2 = dijkstra(graph, v2);
	
	long long answer = min((long long)distance[v1] + distance_v1[v2] + distance_v2[n], (long long)distance[v2] + distance_v2[v1] + distance_v1[n]);
	
	if(answer >= INF){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}