#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void mark(vector<vector<int>>& land, vector<vector<bool>>& visited, int r, int c, int mark_num){
	
	
	int n = land.size();
	
	queue<pair<int, int>> q;
	
	q.push(make_pair(r, c));
	visited[r][c] = true;
	land[r][c] = mark_num;
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			if(visited[next_r][next_c] == false and land[next_r][next_c] == 1){
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
				land[next_r][next_c] = mark_num;
			}
		}
	}
}

int build(vector<vector<int>>& land, int mark_num){
	
	int n = land.size();
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(land[i][j] == mark_num){
				visited[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	
	int result = 0;
	
	while(!q.empty()){
		
		int sz = q.size();
		
		for(int t = 0; t < sz; t++){
			
			pair<int, int> now = q.front();
			q.pop();
	
			for(int i = 0; i < 4; i++){
				
				int next_r = now.first + dr[i];
				int next_c = now.second + dc[i];
				
				if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
					continue;
				}
				
				if(land[next_r][next_c] != 0 and land[next_r][next_c] != mark_num){
					return result;
				}
				
				if(visited[next_r][next_c] == false and land[next_r][next_c] == 0){
					visited[next_r][next_c] = true;
					q.push(make_pair(next_r, next_c));
				}
			}
			
		}
		result++;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> land(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> land[i][j];
		}
	}
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	int mark_num = 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(visited[i][j] == false and land[i][j] == 1){
				mark(land, visited, i, j, mark_num++);
			}
		}
	}
	
	int answer = 987654321;
	
	for(int i = 1; i < mark_num; i++){
		answer = min(answer, build(land, i));
	}
	
	cout << answer;
	
	return 0;
}