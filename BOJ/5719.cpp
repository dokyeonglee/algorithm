#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& graph, int src, int dst){
	
	int n = graph.size();
	vector<int> distance(n, -1);
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] != -1){
			continue;
		}
		
		distance[now] = dist;
		
		for(int next = 0; next < n; next++){
			
			if(distance[next] != -1 or graph[now][next] == -1){
				continue;	
			}
			
			int cost = graph[now][next] + dist;
			
			pq.push(make_pair(-cost, next));	

		}
	}
	
	return distance;
}

void erase_edge(vector<vector<int>>& graph, vector<int>& distance, int dst){
	
	int n = graph.size();
	
	queue<int> q;
	q.push(dst);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < n; i++){
			if(graph[i][now] != -1 and distance[now] == distance[i] + graph[i][now]){
				graph[i][now] = -1;
				q.push(i);
			}	
		}
		
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n, m;
		cin >> n >> m;
		
		if(n == 0 and m == 0){
			break;
		}
		
		vector<vector<int>> graph(n, vector<int>(n, -1));
		
		int src, dst;
		cin >> src >> dst;
		
		for(int i = 0; i < m; i++){
			int u, v, c;
			cin >> u >> v >> c;
			graph[u][v] = c;
		}
		
		vector<int> shortest_distance = dijkstra(graph, src, dst);
		erase_edge(graph, shortest_distance, dst);
		vector<int> almost_shortest_distance = dijkstra(graph, src, dst);
		
		cout << almost_shortest_distance[dst] << '\n';
		
	}
	
	return 0;
}