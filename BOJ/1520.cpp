#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(vector<vector<int>>& map, int r, int c, vector<vector<int>>& dp){
	
	if(r == 0 and c == 0){
		return 1;
	}
	
	int n = map.size();
	int m = map[0].size();
	
	int& ret = dp[r][c];
	
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	for(int i = 0; i < 4; i++){
		
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		
		if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
			continue;
		}
		
		if(map[r][c] < map[next_r][next_c]){
			dp[r][c] += dfs(map, next_r, next_c, dp);
		}
		
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m, -1));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	
	cout << dfs(map, n - 1, m - 1, dp);
	
	return 0;
}