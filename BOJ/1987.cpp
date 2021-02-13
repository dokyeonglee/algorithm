#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int answer = 0;

void dfs(vector<string>& board, vector<bool>& visited, int r, int c, int cnt){
	
	answer = max(answer, cnt);
	
	for(int i = 0; i < 4; i++){
		
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		
		if(next_r < 0 or next_r >= board.size() or next_c < 0 or next_c >= board[0].size()){
			continue;
		}
		
		int next_alphabet = board[next_r][next_c] - 'A';
		
		if(!visited[next_alphabet]){
			visited[next_alphabet] = true;
			dfs(board, visited, next_r, next_c, cnt + 1);
			visited[next_alphabet] = false;
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	cin >> R >> C;
	
	vector<string> board(R);
	for(int i = 0; i < R; i++){
		cin >> board[i];
	}
	
	vector<bool> visited(26, false);
	
	visited[board[0][0] - 'A'] = true;
	
	dfs(board, visited, 0, 0, 1);
	
	cout << answer;
	
	return 0;
}