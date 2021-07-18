#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& H){
	
	int n = H.size();
	int m = H[0].size();
	
	vector<vector<int>> water_height(n, vector<int>(m, 1987654321));
	water_height[0][0] = 0;
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;
	
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	
	while(!pq.empty()){
		
		int height = -pq.top().first;
		pair<int, int> now = pq.top().second;
		pq.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			int next_height = max(height, H[next_r][next_c]);
			
			if(!visited[next_r][next_c] and water_height[next_r][next_c] > next_height){
				visited[next_r][next_c] = true;
				pq.push(make_pair(-next_height, make_pair(next_r, next_c)));
				water_height[next_r][next_c] = next_height;
			}
			
		}
		
	}
	
	int result = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			result += water_height[i][j] - H[i][j];
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> H(n + 2, vector<int>(m + 2));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> H[i][j];
		}
	}
	
	cout << bfs(H);
	
	return 0;
}