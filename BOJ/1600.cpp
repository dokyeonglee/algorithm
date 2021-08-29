#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int knight_dr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int knight_dc[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int bfs(vector<vector<int>>& board, int k){
	
	int h = board.size();
	int w = board[0].size();
	
	vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
	visited[0][0][k] = true;
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, k), make_pair(0, 0)));
	
	int answer = 987654321;
	
	while(!q.empty()){
		
		pair<int, int> cnt = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(now.first == h - 1 and now.second == w - 1){
			return cnt.first;
		}
		
		if(cnt.second > 0){
			for(int i = 0; i < 8; i++){
				
				int next_r = now.first + knight_dr[i];
				int next_c = now .second + knight_dc[i];
				
				if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
					continue;
				}
			
				if(!visited[next_r][next_c][cnt.second - 1] and board[next_r][next_c] == 0){
					visited[next_r][next_c][cnt.second - 1] = true;
					q.push(make_pair(make_pair(cnt.first + 1, cnt.second - 1), make_pair(next_r, next_c)));
				}
				
			}	
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now .second + dc[i];
			
			if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
				continue;
			}
			
			if(!visited[next_r][next_c][cnt.second] and board[next_r][next_c] == 0){
				visited[next_r][next_c][cnt.second] = true;
				q.push(make_pair(make_pair(cnt.first + 1, cnt.second), make_pair(next_r, next_c)));
			}
			
		}
		
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	return answer;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	
	int w, h;
	cin >> w >> h;
	
	vector<vector<int>> board(h, vector<int>(w));
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> board[i][j];
		}
	}
	
	cout << bfs(board, k);
	
	return 0;
}