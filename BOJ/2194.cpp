#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool check(vector<vector<int>>& arr, int r, int c, int a, int b, int dir){
	
	if(r < 0 or r + a - 1 >= arr.size() or c < 0 or c + b - 1 >= arr[0].size()){
		return false;
	}
	
	if(dir % 2 == 0){
		r = r + (a - 1) * (dir / 2);
		for(int i = c; i < c + b; i++){
			if(arr[r][i] == -1){
				return false;
			}
		}
	}else{
		c = c + (b - 1) * (1 - dir / 2);
		for(int i = r; i < r + a; i++){
			if(arr[i][c] == -1){
				return false;
			}
		}	
	}
	return true;
}

int bfs(vector<vector<int>>& arr, pair<int, int>& src, pair<int, int>& dst, int a, int b){
	
	int n = arr.size();
	int m = arr[0].size();
	
	vector<vector<bool>> visited(n, vector<bool>(m));
	visited[src.first][src.second] = true;
		
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, src));
	
	while(!q.empty()){
		int cnt = q.front().first;
		auto now = q.front().second;
		q.pop();
		if(now == dst){
			return cnt;
		}
		for(int k = 0; k < 4; k++){
			int next_r = now.first + dr[k];
			int next_c = now.second + dc[k];
			if(check(arr, next_r, next_c, a, b, k) and !visited[next_r][next_c]){
				visited[next_r][next_c] = true;
				q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
			}
		}
	}
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, a, b, k;
	cin >> n >> m >> a >> b >> k;
	
	vector<vector<int>> arr(n, vector<int>(m));
	for(int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		arr[r - 1][c - 1] = -1;
	}
	
	pair<int, int> src;
	pair<int, int> dst;
	
	cin >> src.first >> src.second;
	cin >> dst.first >> dst.second;
	
	src.first--;
	src.second--;
	dst.first--;
	dst.second--;
	
	cout << bfs(arr, src, dst, a, b);
	
	return 0;
}