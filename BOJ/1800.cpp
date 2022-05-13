#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& graph, int max_cost){
	vector<int> distance(graph.size(), 987654321);
	distance[1] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;	
		}
		
		for(auto e : graph[now]){
			int next = e.first;
			int cost = (e.second > max_cost) + dist;
			if(distance[next] > cost){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
			}
		}
		
	}
	
	return distance[graph.size() - 1];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	int left = 0;
	int right = 1e6;
	int answer = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(dijkstra(graph, mid) <= k){
			answer = mid;
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << answer;
		
	return 0;
}