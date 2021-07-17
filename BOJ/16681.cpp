#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& height, int src){
	
	vector<long long> distance(graph.size(), 9e18);
	distance[src] = 0;
	
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		long long dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(pair<int, int> e : graph[now]){
			
			int next = e.first;
			long long cost = e.second + dist;
			if(height[next] > height[now] and cost < distance[next]){
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
	
	int n, m, d, e;
	cin >> n >> m >> d >> e;
	
	vector<int> height(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> height[i];	
	}
	
	vector<vector<pair<int, int>>>  graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	vector<long long> up = dijkstra(graph, height, 1);
	vector<long long> down = dijkstra(graph, height, n);
	
	long long answer = -9e18;
	for(int i = 2; i < n; i++){
		if(up[i] < 9e18 and down[i] < 9e18){
			answer = max(answer, height[i] * e - (up[i] + down[i]) * d);
		}
	}
	
	if(answer == -9e18){
		cout << "Impossible";
	}else{
		cout << answer;
	}
	
	return 0;
}