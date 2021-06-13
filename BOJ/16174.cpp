#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dr[] = {0, 1};
int dc[] = {1, 0};

bool bfs(vector<vector<int>>& board){
	
	int n = board.size();

	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[0][0] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		int dist = board[now.first][now.second];
		q.pop();
		
		if(now.first == n - 1 and now.second == n - 1){
			return true;
		}
		
		for(int i = 0; i < 2; i++){
			
			int next_r = now.first + dr[i] * dist;
			int next_c = now.second + dc[i] * dist;
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			if(!visited[next_r][next_c]){
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));	
			}
			
		}
		
	}
	
	return false;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> board(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j];
		}
	}
	
	if(bfs(board)){
		cout << "HaruHaru";
	}else{
		cout << "Hing";
	}
	
	return 0;
}