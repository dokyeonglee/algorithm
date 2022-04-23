#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int s_r, int s_c){
	
	visited[s_r][s_c] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(s_r, s_c));
	
	bool check = true;
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
				continue;
			}
			
			if(arr[next_r][next_c] > arr[s_r][s_c]){
				check = false;
			}
			
			if(!visited[next_r][next_c] and arr[next_r][next_c] == arr[s_r][s_c]){
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	
	if(check){
		return 1;
	}else{
		return 0;
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}

	int answer = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j]){
				answer += bfs(arr, visited, i, j);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}