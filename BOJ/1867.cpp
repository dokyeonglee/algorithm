#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d, int x){
	for(int i = 0; i < graph[x].size(); i++){
		int p = graph[x][i];
		if(visited[p]){
			continue;
		}
		visited[p] = true;
		if(d[p] == -1 or dfs(graph, visited, d, d[p])){
			d[p] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	
	vector<int> d(n + 1, -1);
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		vector<bool> visited(n + 1);
		if(dfs(graph, visited, d, i)){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}