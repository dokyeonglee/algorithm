#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(vector<vector<int>>& bamboo, int r, int c, vector<vector<int>>& dp){
	
	int n = dp.size();
	
	int& result = dp[r][c];
	
	if(result != -1){
		return result;
	}
	
	result = 1;
	
	int cnt = 0;
	
	for(int i = 0; i < 4; i++){
		
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		
		if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n or bamboo[next_r][next_c] <= bamboo[r][c]){
			continue;
		}
				
		cnt = max(cnt, dfs(bamboo, next_r, next_c, dp));	
		
	}
	
	return result += cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> bamboo(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n, -1));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> bamboo[i][j];
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			answer = max(answer, dfs(bamboo, i, j, dp));		
		}	
	}
	
	cout << answer;
	
	return 0;
}