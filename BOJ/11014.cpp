#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 1, -1, 1, -1, 1};

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& d, int x){
	for(int i = 0; i < adj[x].size(); i++){
		int now = adj[x][i];
		if(visited[now]){
			continue;
		}
		visited[now] = true;
		if(d[now] == -1 or dfs(adj, visited, d, d[now])){
			d[now] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			for(int j = 0; j < m; j++){
				cnt += (arr[i][j] == 'x');
			}
		}
		
		vector<vector<int>> adj(n * m);
		for(int r = 0; r < n; r++){
			for(int c = 0; c < m; c += 2){
				if(arr[r][c] == '.'){
					for(int i = 0; i < 6; i++){
						int next_r = r + dr[i];
						int next_c = c + dc[i];
						if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
							continue;
						}
						if(arr[next_r][next_c] == '.'){
							adj[r * m + c].push_back(next_r * m + next_c);	
						}
					}
				}
			}
		}
		
		vector<int> d(n * m, -1);
		
		for(int i = 0; i < adj.size(); i++){
			vector<bool> visited(adj.size(), false);
			cnt += dfs(adj, visited, d, i);
		}
		
		cout << n * m - cnt << "\n";
		
	}
	
	return 0;
}