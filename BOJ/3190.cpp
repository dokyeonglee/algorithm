#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int move(vector<vector<int>>& board, deque<pair<int, int>>& snake, int dir, int second){
	
	int n = board.size();
	int result = 0;
	
	for(int i = 0; i < second; i++){
			
		result++;
			
		int next_r = snake.front().first + dr[dir];
		int next_c = snake.front().second + dc[dir];
			
		if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n or board[next_r][next_c] == -1){
			return -result;
		}
			
		snake.push_front(make_pair(next_r, next_c));
				
		if(board[next_r][next_c] == 0){
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
			
		board[next_r][next_c] = -1;
			
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> board(n, vector<int>(n));
	deque<pair<int, int>> snake;
	
	snake.push_back(make_pair(0, 0));
	board[0][0] = -1;
	
	for(int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = 1;
	}
	
	int l;
	cin >> l;
	
	int dir = 1;
	
	int answer = 0;
	int cumulative_time = 0;
	
	while(l--){
		
		int x;
		char turn;
		cin >> x >> turn;
		
		int result = move(board, snake, dir, x - cumulative_time);
		if(result < 0){
			cout << answer - result << "\n";
			return 0;
		}else{
			answer += result;
		}
		
		if(turn == 'L'){
			dir = (dir + 3) % 4;
		}else{
			dir = (dir + 1) % 4;
		}
		
		cumulative_time = x;
		
	}
	
	answer += abs(move(board, snake, dir, n));
	
	cout << answer << "\n";

	return 0;
}