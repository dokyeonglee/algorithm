#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& d, int x){
	for(int p : adj[x]){
		if(visited[p]){
			continue;
		}
		visited[p] = true;
		if(d[p] == -1 or dfs(adj, visited, d, d[p])){
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
	
	int l;
	cin >> l;
	
	set<pair<int, int>> wall;
	for(int i = 0; i < l; i++){
		int x, y;
		cin >> x >> y;
		wall.insert(make_pair(x, y));
		wall.insert(make_pair(y, x));
	}
	
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};
	
	vector<vector<int>> adj(n * m + 1);
	
	for(int r = 1; r <= n; r++){
		for(int c = 2 - r % 2; c <= m; c += 2){
			for(int k = 0; k < 4; k++){
				int next_r = r + dr[k];
				int next_c = c + dc[k];
				if(next_r < 1 or next_r > n or next_c < 1 or next_c > m){
					continue;
				}
				int now = (r - 1) * m + c;
				int next = (next_r - 1) * m + next_c;
				if(wall.count(make_pair(now, next)) == 0){
					adj[now].push_back(next);
				}
			}
		}
	}
	
	vector<int> d(n * m + 1, -1);
	for(int i = 0; i < adj.size(); i++){
		vector<bool> visited(d.size());
		if(dfs(adj, visited, d, i)){
			
		}
	}
	
	for(int i = 1; i <= n * m; i++){
		if(d[i] != -1){
			cout << i << " " << d[i] << "\n";
		}
	}
	
	return 0;
}