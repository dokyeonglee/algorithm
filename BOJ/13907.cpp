#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dijkstra(vector<vector<pair<int, int>>>& graph, int src){
	
	vector<vector<int>> distance(graph.size(), vector<int>(graph.size(), 987654321));
	distance[src][0] = 0;
	
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(src, 0)));
	
	while(!pq.empty()){
		
		int dist = -pq.top().first;
		int now = pq.top().second.first;
		int cnt = pq.top().second.second;
		pq.pop();
		
		if(cnt == graph.size() - 1 or distance[now][cnt] < dist){
			continue;
		}
		
		for(auto e : graph[now]){
			int next = e.first;
			int cost = e.second + dist;
			if(distance[next][cnt + 1] > cost){
				distance[next][cnt + 1] = cost;
				pq.push(make_pair(-cost, make_pair(next, cnt + 1)));
			}
		}
	}
	
	return distance;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	int src, dst;
	cin >> src >> dst;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	vector<vector<int>> distance = dijkstra(graph, src);
	
	int answer = 987654321;
	int tax = 0;
	
	for(int i = 1; i <= n; i++){
		int result = distance[dst][i] + i * tax;
		answer = min(answer, result);
	}
	
	cout << answer << "\n";
	
	for(int i = 0; i < k; i++){
		
		int x;
		cin >> x;
		
		tax += x;
		
		answer = 987654321;
		
		for(int i = 1; i <= n; i++){
			int result = distance[dst][i] + i * tax;
			answer = min(answer, result);
		}
	
		cout << answer << "\n";
	}
	
	
	return 0;
}