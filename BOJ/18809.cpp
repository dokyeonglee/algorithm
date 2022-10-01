#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, queue<pair<int, int>>& q){
	
	int result = 0;
	
	int n = arr.size();
	int m = arr[0].size();
	int t = 3;
	
	while(!q.empty()){
		int sz = q.size();
		for(int a = 0; a < sz; a++){
			auto now = q.front();
			q.pop();
			for(int i = 0; i < 4; i++){
				int next_r = now.first + dr[i];
				int next_c = now.second + dc[i];
				if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
					continue;
				}
				if(arr[next_r][next_c] == 1 or arr[next_r][next_c] == 2){
					if(arr[now.first][now.second] == t){
						arr[next_r][next_c] = t + 1;
                        q.push(make_pair(next_r, next_c));
					}else if(arr[now.first][now.second] == -t){
						arr[next_r][next_c] = -t - 1;
                        q.push(make_pair(next_r, next_c));
					}
				}else if(abs(arr[now.first][now.second] + arr[next_r][next_c]) == 1){
					result++;
					arr[next_r][next_c] = 0;
				}
			}
		}
		t++;
	}
	
	return result;
}


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, g, r;
	cin >> n >> m >> g >> r;
	
	vector<vector<int>> arr(n, vector<int>(m));
	vector<pair<int, int>> pos;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 2){
				pos.push_back(make_pair(i, j));
			}
		}
	}

	string str = string(g, 'G') + string(r, 'R') + string(pos.size() - g - r, 'X');
	
	int answer = 0;
	do{
		auto temp(arr);
		queue<pair<int, int>> q;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == 'G'){
				temp[pos[i].first][pos[i].second] = 3;
				q.push(pos[i]);
			}else if(str[i] == 'R'){
				temp[pos[i].first][pos[i].second] = -3;
				q.push(pos[i]);
			}
		}
		answer = max(answer, bfs(temp, q));
	}while(next_permutation(str.begin(), str.end()));
	
	cout << answer;
	
	return 0;
}