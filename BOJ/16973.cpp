#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& grid, vector<vector<int>>& dp, pair<int, int> src, int h, int w, pair<int, int> dst){
	
	int n = grid.size();
	int m = grid[0].size();
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[src.first][src.second] = true;
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, src));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(now == dst){
			return cnt;
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 1 or next_r + h - 1 >= n or next_c < 1 or next_c + w - 1 >= m){
				continue;
			}
			
			if(dp[next_r + h - 1][next_c + w - 1] - dp[next_r - 1][next_c + w - 1]
			- dp[next_r + h - 1][next_c - 1] + dp[next_r - 1][next_c - 1] > 0){
				continue;
			}
			
			if(!visited[next_r][next_c] and grid[next_r][next_c] == 0){
				visited[next_r][next_c] = true;
				q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));	
			}
		}
		
	}
	
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> grid(n + 1, vector<int>(m + 1));
	vector<vector<int>> dp(grid);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> grid[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
		}
	}
	
	int h, w, sr, sc, fr, fc;
	cin >> h >> w >> sr >> sc >> fr >> fc;
	
	cout << bfs(grid, dp, make_pair(sr, sc), h, w, make_pair(fr, fc));
	
	return 0;
}