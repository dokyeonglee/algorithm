#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<vector<int>>& dp, int now){
	visited[now] = true;
	dp[now][0] = 1;
	for(int i = 0; i < graph[now].size(); i++){
		int next = graph[now][i];
		if(!visited[next]){
			dfs(graph, visited, dp, next);
			dp[now][1] += dp[next][0];
			dp[now][0] += min(dp[next][1], dp[next][0]);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(2));
	vector<bool> visited(n + 1, false);
	
	dfs(graph, visited, dp, 1);
	
	cout << min(dp[1][0], dp[1][1]);
	
	return 0;
}