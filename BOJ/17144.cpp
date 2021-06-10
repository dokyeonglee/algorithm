#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void diffusion(vector<vector<int>>& map){
	
	int R = map.size();
	int C = map[0].size();
	
	vector<vector<int>> temp(R, vector<int>(C));
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			
			int cnt = 0;
			
			if(map[i][j] <= 0){
				continue;
			}
				
			for(int k = 0; k < 4; k++){
				
				int next_r = i + dr[k];
				int next_c = j + dc[k];
				
				if(next_r < 0 or next_r >= R or next_c < 0 or next_c >= C){
					continue;
				}
				
				if(map[next_r][next_c] == -1){
					continue;
				}
				
				cnt++;
				temp[next_r][next_c] += map[i][j] / 5;
			}
			
			map[i][j] -= map[i][j] / 5 * cnt;
		}
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			map[i][j] += temp[i][j];
		}
	}
	
}

int cycle(vector<vector<int>>& map, int row, int dir){
	
	int R = map.size();
	int C = map[0].size();
	
	int result = map[row + dir][0];
	
	int r = row + dir;
	int c = 0;
	
	while(r > 0 and r < R - 1){
		map[r][0] = map[r + dir][0];
		r += dir;
	}
	
	while(c < C - 1){
		map[r][c] = map[r][c + 1];
		c++;
	}
	
	while(r != row){
		map[r][C - 1] = map[r - dir][C - 1];
		r -= dir;
	}
	
	while(c > 1){
		map[r][c] = map[r][c - 1];
		c--;
	}
	
	map[row][0] = -1;
	map[row][1] = 0;
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C, T;
	cin >> R >> C >> T;
	
	vector<vector<int>> map(R, vector<int>(C));
	vector<int> pos;
	
	int answer = 0;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> map[i][j];
			if(map[i][j] == -1){
				pos.push_back(i);
			}else{
				answer += map[i][j];
			}
		}
	}
	
	while(T--){
		diffusion(map);
		answer -= cycle(map, pos[0], -1);
		answer -= cycle(map, pos[1], 1);
	}
	
	cout << answer;
	
	return 0;
}