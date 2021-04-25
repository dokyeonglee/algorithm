#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& map, queue<pair<int, int>>& q, int zero_cnt){
	
	int n = map.size();
	int m = map[0].size();
	
	int result = 0;
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		if(zero_cnt == 0){
			break;
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			
			if(map[next_r][next_c] == 0 or map[next_r][next_c] == -2){
				if(map[next_r][next_c] == 0){
					zero_cnt--;
				}
				map[next_r][next_c] = map[now.first][now.second] + 1;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
	
}

int next(int n){
	
	int least_nonzero = n & -n;
	int temp = (n + least_nonzero);
	temp &= -temp;
	temp /= least_nonzero;
	return n + least_nonzero + (temp >> 1) - 1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int zero_cnt = 0;
	
	vector<vector<int>> map(n, vector<int>(n));
	vector<pair<int, int>> pos;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> map[i][j];
			if(map[i][j] == 2){
				pos.push_back(make_pair(i, j));
			}else if(map[i][j] == 0){
				zero_cnt++;
			}
		}
	}
	
	int s = (1 << m) - 1;
	int e = s << (pos.size() - m);
	int answer = 987654321;
	
	for(int i = s; i <= e; i = next(i)){
		vector<vector<int>> temp(map);
		queue<pair<int, int>> q;	
		
		for(int j = 0; j < pos.size(); j++){
			if((i & (1 << j)) == 0){
				temp[pos[j].first][pos[j].second] = -2;
			}else{
				q.push(make_pair(pos[j].first, pos[j].second));
			}
		}
		
		bfs(temp, q, zero_cnt);
		
		int result = 0;
		int cnt = 0;
		
		for(int r = 0; r < n; r++){
			for(int c = 0; c < n; c++){
				result = max(result, temp[r][c] - 2);
				if(temp[r][c] == 0){
					cnt++;
				}
			}
		}
		
		if(cnt == 0) answer = min(answer, result);
		
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}