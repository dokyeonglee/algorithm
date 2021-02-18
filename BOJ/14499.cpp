#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r, c, k;
	cin >> n >> m >> r >> c >> k;
	
	vector<vector<int>> board(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	
	vector<int> dice(7);
	
	for(int i = 0; i < k; i++){
		
		int dir;
		cin >> dir;
		
		int next_r = r + dr[dir];
		int next_c = c + dc[dir];
		
		if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
			
			continue;
			
		}else{
			
			r = next_r;
			c = next_c;
			
			vector<int> temp(dice);
			
			if(dir == 1){
				temp[1] = dice[4];
				temp[6] = dice[3];
				temp[3] = dice[1];
				temp[4] = dice[6];
			}else if(dir == 2){
				temp[1] = dice[3];
				temp[6] = dice[4];
				temp[3] = dice[6];
				temp[4] = dice[1];
			}else if(dir == 3){
				temp[1] = dice[5];
				temp[6] = dice[2];
				temp[2] = dice[1];
				temp[5] = dice[6];
			}else if(dir == 4){
				temp[1] = dice[2];
				temp[6] = dice[5];
				temp[2] = dice[6];
				temp[5] = dice[1];
			}
						
			if(board[r][c] == 0){
				board[r][c] = temp[6];	
			}else{
				temp[6] = board[r][c];
				board[r][c] = 0;	
			}
			
			cout << temp[1] << '\n';
			
			dice = temp;
			
		}
	}
	
	
	return 0;
}