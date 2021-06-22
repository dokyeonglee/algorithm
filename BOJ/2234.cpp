#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int bfs(vector<vector<int>>& map, vector<vector<int>>& visited, int r, int c, int num){
	
	int result = 1;
	
	visited[r][c] = num;
	
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		int wall = map[now.first][now.second];
		
		for(int i = 0; i < 4; i++){
			
			if(wall & (1 << i)){
				continue;
			}else{
				
				int next_r = now.first + dr[i];
				int next_c = now.second + dc[i];
				
				if(next_r < 0 or next_r >= map.size() or next_c < 0 or next_c >= map[0].size()){
					continue;	
				}
				
				if(visited[next_r][next_c] == 0){
					result++;
					visited[next_r][next_c] = num;
					q.push(make_pair(next_r, next_c));
				}
				
			}
		}
		
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> m >> n;
	
	vector<vector<int>> map(n, vector<int>(m));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
		}
	}
	
	int max_size = 0;
	int cnt = 0;
	
	vector<vector<int>> visited(n, vector<int>(m, 0));
	vector<int> size_v(1, 0);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				int result = bfs(map, visited, i, j, ++cnt);
				size_v.push_back(result);
				max_size = max(max_size, result);
			}
		}
	}
	
	cout << cnt << "\n";
	cout << max_size << "\n";
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i + 1 < n and visited[i][j] != visited[i + 1][j]){
				max_size = max(max_size, size_v[visited[i][j]] + size_v[visited[i + 1][j]]);
			}
			if(j + 1 < m and visited[i][j] != visited[i][j + 1]){
				max_size = max(max_size, size_v[visited[i][j]] + size_v[visited[i][j + 1]]);
			}
		}
	}
	
	cout << max_size;
	
	return 0;
}