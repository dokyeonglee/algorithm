#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& ice, vector<vector<bool>>& visited, int x, int y){
	
	int n = ice.size();
	int m = ice[0].size();
	
	queue<pair<int, int>> q;
	
	visited[x][y] = true;
	q.push(make_pair(x, y));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		int cnt = 0;
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(ice[next_r][next_c] == 0){
				cnt++;
			}
			
			if(visited[next_r][next_c] == false and ice[next_r][next_c] > 0){
				q.push(make_pair(next_r, next_c));
				visited[next_r][next_c] = true;
			}
			
		}
		
		if(ice[now.first][now.second] <= cnt){
			ice[now.first][now.second] = -1;
		}else{
			ice[now.first][now.second] -= cnt;
		}
		
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> ice(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ice[i][j];		
		}
	}
	
	int answer = -1;
	while(1){
		
		answer++;
		
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		
		int cnt = 0;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(visited[i][j] == false and ice[i][j] > 0){
					bfs(ice, visited, i, j);
					cnt++;
				}
			}
		}
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(ice[i][j] == -1){
					ice[i][j] = 0;
				}
			}
		}
		

		
		if(cnt >= 2){
			break;
		}
		
		if(cnt == 0){
			answer = 0;
			break;
		}

	}
	
	cout << answer;
	
	return 0;
}