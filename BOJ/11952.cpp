#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, queue<pair<int, int>>& zombie, int s, vector<int>& charge, int p, int q){
	
	while(!zombie.empty()){
		
		int now = zombie.front().first;
		int dist = zombie.front().second;
		zombie.pop();
		
		if(dist == s){
			continue;
		}
		
		for(int next : graph[now]){
			if(charge[next] == p){
				charge[next] = q;
				zombie.push(make_pair(next, dist + 1));	
			}
		}
		
	}
	
}

long long dijkstra(vector<vector<int>>& graph, vector<int>& charge){
	
	priority_queue<pair<long long, int>> pq;
	vector<long long> distance(graph.size(), -1);
	
	pq.push(make_pair(0, 1));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		long long dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] != -1){
			continue;
		}
		
		distance[now] = dist;
		
		for(int next : graph[now]){
			
			if(distance[next] != -1 or charge[next] == -1){
				continue;
			}
			
			long long cost = charge[next] + dist;
			pq.push(make_pair(-cost, next));
			
		}
		
	}
	
	return distance[graph.size() - 1];
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, s;
	cin >> n >> m >> k>> s;
	
	int p, q;
	cin >> p >> q;
	
	vector<int> charge(n + 1, p);
	queue<pair<int, int>> zombie;
	
	int u, v;
	
	for(int i = 0; i < k; i++){
		cin >> u;
		charge[u] = -1;
		zombie.push(make_pair(u, 0));	
	}
	
	vector<vector<int>> graph(n + 1);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	bfs(graph, zombie, s, charge, p, q);
	
	cout << dijkstra(graph, charge) - charge[n];
	
	
	return 0;
}