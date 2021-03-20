#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src){
	
	vector<int> distance(graph.size(), -1);
	
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
		
		for(pair<int, int> e : graph[now]){
			
			int next = e.second;
			
			if(distance[next] != -1){
				continue;
			}
			
			int cost = e.first + dist;
			
			pq.push(make_pair(-cost, next));
			
		}
	}
	
	return distance;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n, m, t;
		cin >> n >> m >> t;
		
		int s, g, h;
		cin >> s >> g >> h;
		
		int g_h_dist = 0;
		
		vector<vector<pair<int, int>>> graph(n + 1);
		for(int i = 0; i < m; i++){
			
			int u, v, c;
			cin >> u >> v >> c;
			
			if((u == g and v == h) or (u == h and v == g)){
				g_h_dist = c;
			}
			
			graph[u].push_back(make_pair(c, v));
			graph[v].push_back(make_pair(c, u));
		}
		
		vector<int> distance = dijkstra(graph, s);

		if(distance[g] > distance[h]){
			swap(g, h);
		}
		
		vector<int> from_h_distance = dijkstra(graph, h);
		
		vector<int> answer;
		
		for(int i = 0; i < t; i++){
			int v;
			cin >> v;
			
			int dist = distance[g];
			int h_dist = from_h_distance[v];
			
			if(dist != - 1 and h_dist != -1 and dist + g_h_dist + h_dist == distance[v]){
				answer.push_back(v);		
			}
		}	
		
		sort(answer.begin(), answer.end());
		
		for(int i = 0; i < answer.size(); i++){
			cout << answer[i] << " ";
		}
		cout << '\n';
		
	}
	
	
	return 0;
}