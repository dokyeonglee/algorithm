#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using piiii = pair<pii, pii>;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& map, vector<pair<int, int>>& pos){
	
	int h = map.size();
	int w = map[0].size();
	
	vector<vector<int>> cnt(h, vector<int>(w, 987654321));
	cnt[pos[0].first][pos[0].second] = 0;
	
	queue<piiii> q;
	for(int i = 0; i < 4; i++){
		q.push(make_pair(make_pair(pos[0].first, pos[0].second), make_pair(i, 0)));
	}
	
	while(!q.empty()){
		
		pair<int, int> now = q.front().first;
		int dir = q.front().second.first;
		int now_cnt = q.front().second.second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
				continue;
			}
			
			if(map[next_r][next_c] == '*'){
				continue;
			}
			
			int next_cnt = now_cnt + (dir != i);
			if(cnt[next_r][next_c] >= next_cnt){
				cnt[next_r][next_c] = next_cnt;
				q.push(make_pair(make_pair(next_r, next_c), make_pair(i, next_cnt)));
			}
			
		}
		
	}
	
	return cnt[pos[1].first][pos[1].second];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int w, h;
	cin >> w >> h;
	
	vector<string> map(h);
	
	vector<pair<int, int>> pos;
	
	for(int i = 0; i < h; i++){
		cin >> map[i];
		for(int j = 0; j < w; j++){
			if(map[i][j] == 'C'){
				pos.push_back(make_pair(i, j));
			}
		}
	}
	
	cout << bfs(map, pos);
	
	return 0;
}