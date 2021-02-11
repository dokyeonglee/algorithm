#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited){

	queue<pair<int, int>> q;
	
	visited[x][y] = true;
	q.push(make_pair(x, y));
	
	int cnt = 1;
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_x = now.first + dx[i];
			int next_y = now.second + dy[i];
			
			if(next_x < 0 or next_x >= grid.size() or next_y < 0 or next_y >= grid[0].size()){
				continue;
			}
			
			if(!visited[next_x][next_y] and grid[next_x][next_y] == 0){
				visited[next_x][next_y] = true;
				q.push(make_pair(next_x, next_y));
				cnt++;
			}
		}
	}
	
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> grid(m, vector<int>(n));
	vector<vector<bool>> visited(m, vector<bool>(n));
	
	for(int i = 0; i < k; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int x = x1; x < x2; x++){
			for(int y = y1; y < y2; y++){
				grid[x][y] = 1;
			}
		}
	}

	vector<int> answer;
	
	for(int i = 0; i < grid.size(); i++){
		for(int j = 0; j < grid[i].size(); j++){
			if(!visited[i][j] and grid[i][j] == 0){
				answer.push_back(bfs(grid, i, j, visited));
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	
	cout << answer.size() << '\n';
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}