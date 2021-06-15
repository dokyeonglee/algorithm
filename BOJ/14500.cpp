#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int t_block_dr[4][4] = {{0, 0, 0, 1}, {0, 1, 1, 2}, {-1, 0, 0, 0}, {-1, 0, 0, 1}};
int t_block_dc[4][4] = {{0, 1, 2, 1}, {0, 0, 1, 0}, {1, 0, 1, 2}, {1, 0, 1, 1}};

int dfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int r, int c, int sum, int depth){
	
	if(depth == 4){
		return sum;	
	}
	
	int n = board.size();
	int m = board[0].size();
	
	int result = sum;
	
	for(int i = 0; i < 4; i++){
		
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		
		if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
			continue;
		}
		
		if(!visited[next_r][next_c]){
			visited[next_r][next_c] = true;
			result = max(result, dfs(board, visited, next_r, next_c, sum + board[next_r][next_c], depth + 1));
			visited[next_r][next_c] = false;
		}
		
	}
	
	return result;
}

int t_block(vector<vector<int>>& board, int r, int c){
	
	int n = board.size();
	int m = board[0].size();
	
	int result = 0;
	
	for(int i = 0; i < 4; i++){
		
		int sum = 0;
		bool valid = true;
		
		for(int j = 0; j < 4; j++){
			
			int next_r = r + t_block_dr[i][j];
			int next_c = c + t_block_dc[i][j];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				valid = false;
				break;
			}
			
			sum += board[next_r][next_c];
			
		}
		
		if(valid){
			result = max(result, sum);
		}
		
	}
	
	return result;
	
}


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> board(n, vector<int>(m));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			visited[i][j] = true;
			answer = max(answer, dfs(board, visited, i, j, board[i][j], 1));
			visited[i][j] = false;
			
			answer = max(answer, t_block(board, i, j));
			
		}
	}
	
	cout << answer << "\n";
	
	return 0;
}