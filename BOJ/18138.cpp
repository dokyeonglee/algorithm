#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d, int now){
	for(int next : graph[now]){
		if(visited[next]){
			continue;
		}
		visited[next] = true;
		if(d[next] == -1 or dfs(graph, visited, d, d[next])){
			d[next] = now;
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
	
	vector<int> shirts(n);
	for(int i = 0; i < n; i++){
		cin >> shirts[i];
	}
	
	vector<int> collar(m);
	for(int i = 0; i < m; i++){
		cin >> collar[i];
	}
	
	vector<vector<int>> graph(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((shirts[i] <= 2 * collar[j] and 4 * collar[j] <= 3 * shirts[i]) or (shirts[i] <= collar[j] and 4 * collar[j] <= 5 * shirts[i])){
				graph[i].push_back(j);
			}
		}
	}
	
	vector<int> d(m, -1);
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		vector<bool> visited(m);
		if(dfs(graph, visited, d, i)){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}