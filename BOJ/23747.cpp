#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	cin >> R >> C;
	
	vector<string> board(R);
	for(int i = 0; i < R; i++){
		cin >> board[i];
	}
	
	int r, c;
	cin >> r >> c;
	
	r--;
	c--;
	
	string path;
	cin >> path;
	
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(R, vector<bool>(C));
	
	for(int i = 0; i < path.size(); i++){
		switch(path[i]){
			case 'W':
				visited[r][c] = true;
				q.push(make_pair(r, c));
				break;
			case 'U':
				r--;
				break;
			case 'D':
				r++;
				break;
			case 'L':
				c--;
				break;
			case 'R':
				c++;
				break;
		}
	}
	
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			if(next_r < 0 or next_r >= R or next_c < 0 or next_c >= C){
				continue;
			}
			if(!visited[next_r][next_c] and board[next_r][next_c] == board[now.first][now.second]){
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	
	visited[r][c] = true;
	for(int i = 0; i < 4; i++){
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if(next_r < 0 or next_r >= R or next_c < 0 or next_c >= C){
			continue;
		}
		visited[next_r][next_c] = true;
	}
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(visited[i][j]){
				cout << '.';
			}else{
				cout << '#';
			}
		}
		cout << "\n";
	}
	
	return 0;
}