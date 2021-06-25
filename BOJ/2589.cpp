#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& map, int r, int c){
	
	int R = map.size();
	int C = map[0].size();
	
	vector<vector<int>> distance(R, vector<int>(C));
	distance[r][c] = 1;
	
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	int result = 0;
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		int dist = distance[now.first][now.second];
		
		result = max(result, dist);
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			
			if(next_r < 0 or next_r >= R or next_c < 0 or next_c >= C){
				continue;
			}
			
			if(map[next_r][next_c] == 'L' and distance[next_r][next_c] == 0){
				distance[next_r][next_c] = dist + 1;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	
	return result - 1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	cin >> R >> C;
	
	vector<string> map(R);
	
	for(int i = 0; i < R; i++){
		cin >> map[i];
	}
	
	int answer = 0;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(map[i][j] == 'L'){
				answer = max(answer, bfs(map, i, j));
			}
		}
	}
	
	cout << answer;
	
	return 0;
}