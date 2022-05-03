#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr){
	
	int n = arr.size();
	int m = arr[0].size();
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	
	int result = 987654321;
	
	while(!q.empty()){
		
		int time = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(next_r == n - 1 and next_c == m - 1){
				result = min(result, time + 1);
				continue;
			}
			
			if(arr[next_r][next_c] == 2){
				result = min(result, time + 1 + n - 1 - next_r + m - 1 - next_c);
				continue;
			}
			
			if(!visited[next_r][next_c] and arr[next_r][next_c] != 1){
				visited[next_r][next_c] = true;
				q.push(make_pair(time + 1, make_pair(next_r, next_c)));
			}
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, t;
	cin >> n >> m >> t;
	
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
		}
	}
	
	int answer = bfs(arr);
	
	if(answer > t){
		cout << "Fail";
	}else{
		cout << answer;
	}
	
	
	return 0;
}