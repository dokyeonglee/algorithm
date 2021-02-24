#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& map, int r, int c){
	
	int n = map.size();
	int m = map[0].size();
	
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2)));
	dist[0][0][0] = 1;
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(r, c)));
	
	int answer = 987654321;
	
	while(!q.empty()){
		
		int flag = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		if(now.first == n - 1 and now.second == m - 1){
			return dist[now.first][now.second][flag];
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(dist[next_r][next_c][flag]){
				continue;
			}
			
			if(map[next_r][next_c] == 0){
				dist[next_r][next_c][flag] = dist[now.first][now.second][flag] + 1;
				q.push(make_pair(flag, make_pair(next_r, next_c)));	
			}
			
			if(map[next_r][next_c] == 1 and flag == 0){
				dist[next_r][next_c][1] = dist[now.first][now.second][flag] + 1;
				q.push(make_pair(1, make_pair(next_r, next_c)));	
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
	
	vector<vector<int>> map(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			map[i][j] = str[j] - '0';
		}
	}
	
	cout << bfs(map, 0, 0);
	
	return 0;
}