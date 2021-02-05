#include <iostream>
#include <vector>

using namespace std;

int dp[100001][2];
bool visited[10001];

void dfs(vector<vector<int>>& tree, vector<int>& population, int s){
	
	for(int next : tree[s]){
		if(visited[next]){
			continue;
		}
		visited[next] = true;
		dfs(tree, population, next);
		dp[s][1] += dp[next][0];
		dp[s][0] += max(dp[next][0], dp[next][1]);
	}
	
	dp[s][1] += population[s];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> population(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> population[i];
	}
	
	vector<vector<int>> tree(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	visited[1] = true;	
	dfs(tree, population, 1);
	
	cout << max(dp[1][0], dp[1][1]);
	
	return 0;
	
}