#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int k){
	
	vector<priority_queue<int>> distance(graph.size()); 
	distance[1].push(0);
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		for(auto e : graph[now]){
			
			int next = e.first;
			int cost = dist + e.second;
			
			if(distance[next].size() < k){
				pq.push(make_pair(-cost, next));
				distance[next].push(cost);
			}else if(distance[next].top() > cost){
				distance[next].pop();
				pq.push(make_pair(-cost, next));
				distance[next].push(cost);
			}
			
		}
		
	}
	
	vector<int> result(graph.size());
	for(int i = 1; i < graph.size(); i++){
		if(distance[i].size() != k){
			result[i] = -1;
		}else{
			result[i] = distance[i].top();
		}
	}
	
	return result;
	
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
	}
	
	vector<int> answer = dijkstra(graph, k);
	for(int i = 1; i <= n; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}