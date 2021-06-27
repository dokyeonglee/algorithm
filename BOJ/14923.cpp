#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& maze, pair<int, int> src, pair<int, int> dst){
	
	int n = maze.size();
	int m = maze[0].size();
	
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	visited[src.first][src.second][0] = true;
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, 0), src));
	
	while(!q.empty()){
		
		int cnt = q.front().first.first;
		int used = q.front().first.second;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(now == dst){
			return cnt;
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			
			if(!visited[next_r][next_c][used]){
				
				if(maze[next_r][next_c] == 0){
					visited[next_r][next_c][used] = true;
					q.push(make_pair(make_pair(cnt + 1, used), make_pair(next_r, next_c)));
				}
				
				if(maze[next_r][next_c] == 1 and used == 0){
					visited[next_r][next_c][1] = true;
					q.push(make_pair(make_pair(cnt + 1, used + 1), make_pair(next_r, next_c)));
				}
			}
			
		}
		
	}
	
	return -1;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int hx, hy;
	cin >> hx >> hy;
	
	int ex, ey;
	cin >> ex >> ey;
	
	vector<vector<int>> maze(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> maze[i][j];
		}
	}
	
	cout << bfs(maze, make_pair(hx - 1, hy - 1), make_pair(ex - 1, ey - 1));
	
	return 0;
}