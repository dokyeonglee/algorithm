#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(vector<string>& board, string& word, vector<vector<vector<int>>>& dp, int r, int c, int idx, int k){
	
	if(dp[r][c][idx] != -1){
		return dp[r][c][idx];	
	}

	if(idx >= word.size()){
		return 1;
	}
	
	int n = dp.size();
	int m = dp[0].size();
		
	dp[r][c][idx] = 0;
	
	for(int i = 0; i < 4; i++){
		for(int j = 1; j <= k; j++){
			
			int next_r = r + dr[i] * j;
			int next_c = c + dc[i] * j;
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(board[next_r][next_c] != word[idx]){
				continue;
			}
			
			dp[r][c][idx] += dfs(board, word, dp, next_r, next_c, idx + 1, k);
			
		}	
	}
	
	return dp[r][c][idx];
	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<string> board(n);
	for(int i = 0; i < n; i++){
		cin >> board[i];
	}
	
	string word;
	cin >> word;

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(word.size() + 1, -1)));
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == word[0]){
				answer += dfs(board, word, dp, i, j, 1, k);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}