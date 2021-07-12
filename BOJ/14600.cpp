#include <iostream>
#include <vector>

using namespace std;

int tile_num = 0;

bool can_fill(vector<vector<int>>& board, int r, int c, int sz){
	for(int i = r; i < r + sz; i++){
		for(int j = c; j < c + sz; j++){
			if(board[i][j] != 0){
				return false;
			}
		}
	}
	return true;
}

void fill_tile(vector<vector<int>>& board, int r, int c, int sz){
	
	tile_num++;
	
	if(can_fill(board, r, c, sz / 2)){
		board[r + sz / 2 - 1][c + sz / 2 - 1] = tile_num;
	}
	if(can_fill(board, r, c + sz / 2, sz / 2)){
		board[r + sz / 2 - 1][c + sz / 2] = tile_num;
	}
	if(can_fill(board, r + sz / 2, c, sz / 2)){
		board[r + sz / 2][c + sz / 2 - 1] = tile_num;
	}
	if(can_fill(board, r + sz / 2, c + sz / 2, sz / 2)){
		board[r + sz / 2][c + sz / 2 ] = tile_num;
	}
	
	if(sz == 2){
		return;
	}
	
	fill_tile(board, r, c, sz / 2);
	fill_tile(board, r + sz / 2, c, sz / 2);
	fill_tile(board, r, c + sz / 2, sz / 2);
	fill_tile(board, r + sz / 2, c + sz / 2, sz / 2);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	
	vector<vector<int>> board(1 << k, vector<int>(1 << k));
	
	int r, c;
	cin >> r >> c;
	
	board[c - 1][r - 1] = -1;
	
	fill_tile(board, 0, 0, 1 << k);
	
	for(int i = board.size() - 1; i >= 0; i--){
		for(int j = 0; j < board.size(); j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}