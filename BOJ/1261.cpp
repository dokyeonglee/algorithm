#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& board){
	
	int n = board.size();
	int m = board[0].size();
	
	vector<vector<int>> dist(n, vector<int>(m, 987654321));
	dist[0][0] = 0;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(board[next_r][next_c] == 1){
				if(dist[next_r][next_c] > dist[now.first][now.second] + 1){
					dist[next_r][next_c] = dist[now.first][now.second] + 1;
					q.push(make_pair(next_r, next_c));
				}
			}else if(board[next_r][next_c] == 0){
				if(dist[next_r][next_c] > dist[now.first][now.second]){
					dist[next_r][next_c] = dist[now.first][now.second];
					q.push(make_pair(next_r, next_c));
				}
			}
		}
	}
	

	return dist[n - 1][m - 1];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> m >> n;
	
	vector<vector<int>> board(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			board[i][j] = str[j] - '0';
		}
	}
	
	cout << bfs(board);
	
	return 0;
}