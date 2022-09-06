#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, src, dst, m;
	cin >> n >> src >> dst >> m;
	
	vector<vector<pair<int, int>>> adj(n);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
	}
	
	vector<long long> earn(n);
	for(int i = 0; i < n; i++){
		cin >> earn[i];
		earn[i] = -earn[i];
	}
	
	vector<long long> distance(n, 987654321);
	distance[src] = earn[src];
	queue<int> cycle;
	
	for(int i = 0; i < n; i++){
		for(int u = 0; u < n; u++){
			if(distance[u] == 987654321){
				continue;
			}
			for(auto [v, c] : adj[u]){
				if(distance[v] > distance[u] + c + earn[v]){
					distance[v] = distance[u] + c + earn[v];
					if(i == n - 1){
						cycle.push(u);
					}
				}	
			}
		}
	}
	
	vector<bool> visited(n);
	
	while(!cycle.empty()){
		int u = cycle.front();
		cycle.pop();
		if(u == dst){
			cout << "Gee";
			return 0;
		}
		for(auto [v, c] : adj[u]){
			if(!visited[v]){
				visited[v] = true;
				cycle.push(v);
			}
		}
	}
	
	if(distance[dst] == 987654321){
		cout << "gg";
	}else{
		cout << -distance[dst];
	}
	
	return 0;
}