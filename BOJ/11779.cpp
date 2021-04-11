#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<vector<int>, vector<int>> dijkstra(vector<vector<pair<int, int>>>& graph, int src){
	
	vector<int> distance(graph.size(), 987654321);
	vector<int> predecessor(graph.size(), -1);
	
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
			
			int next = e.second;
			int cost = e.first + dist;
			
			if(distance[next] > cost){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
				predecessor[next] = now;	
			}
		}
	}
	
	return make_pair(distance, predecessor);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(c, v));	
	}
	
	int src, dst;
	cin >> src >> dst;
	
	pair<vector<int>, vector<int>> answer = dijkstra(graph, src);
	vector<int> distance = answer.first;
	vector<int> predecessor = answer.second;
	vector<int> route;
	
	int now = dst;
	
	while(now != -1){
		route.push_back(now);
		now = predecessor[now];
	}
	
	cout << distance[dst] << '\n';
	cout << route.size() << '\n';
	for(int i = route.size() - 1; i >= 0; i--){
		cout << route[i] << " ";
	}
	
	return 0;
}