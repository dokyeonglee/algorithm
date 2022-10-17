#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& d, int x, int t){
	for(int p : adj[x]){
		if(visited[p] == t){
			continue;
		}
		visited[p] = t;
		if(d[p] == -1 or dfs(adj, visited, d, d[p], t)){
			d[p] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int y;
			cin >> y;
			adj[i].push_back(y);
		}
	}
	
	vector<int> d(m + 1, -1);
	
	int answer = 0;
	int result = 0;
	
	vector<int> visited(m + 1, -1);
	
	for(int i = 0; i < n; i++){
		if(dfs(adj, visited, d, i, i)){
			answer++;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(dfs(adj, visited, d, i, i + n)){
			result++;
		}
	}
	
	cout << answer + min(result, k);
	
	return 0;
}