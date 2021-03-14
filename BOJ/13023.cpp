#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, int idx, int cnt){
	
	if(cnt == 5){
		return true;
	}
	
	visited[idx] = true;
	for(int v : graph[idx]){
		if(visited[v] == true){
			continue;
		}
		if(dfs(graph, visited, v, cnt + 1)){
			return true;
		}
	}
	visited[idx] = false;
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i = 0; i < n; i++){
		vector<bool> visited(n, false);
		if(dfs(graph, visited, i, 1)){
			cout << 1;
			return 0;
		}
	}
	
	cout << 0;
	
	return 0;
}