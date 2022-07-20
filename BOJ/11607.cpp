#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr){
	
	int n = arr.size();
	int m = arr[0].size();
	
	auto dst = make_pair(n - 1, m - 1);
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(0, 0)));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		auto now = q.front().second;
		q.pop();
		
		if(now == dst){
			return cnt;
		}
		
		for(int i = 0; i < 4; i++){
			int next_r = now.first + dr[i] * (arr[now.first][now.second] - '0');
			int next_c = now.second + dc[i] * (arr[now.first][now.second] - '0');
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			if(!visited[next_r][next_c]){
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
	
	int n, m;
	cin >> n >> m;
	
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int answer = bfs(arr);
	if(answer == -1){
		cout << "IMPOSSIBLE";
	}else{
		cout << answer;
	}
	
	return 0;
}