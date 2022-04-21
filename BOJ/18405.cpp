#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& arr, queue<pair<int, int>>& q, int num){
	int n = q.size();
	for(int i = 0; i < n; i++){
		pair<int, int> now = q.front();
		q.pop();
		for(int j = 0; j < 4; j++){
			int next_r = now.first + dr[j];
			int next_c = now.second + dc[j];
			if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
				continue;
			}
			if(arr[next_r][next_c] == 0){
				arr[next_r][next_c] = num;
				q.push(make_pair(next_r, next_c));
			}		
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> arr(n, vector<int>(n));
	vector<queue<pair<int, int>>> q(k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
			if(arr[i][j]){
				q[arr[i][j] - 1].push(make_pair(i, j));
			}
		}
	}
	
	int s, x, y;
	cin >> s >> x >> y;
	
	for(int i = 0; i < s; i++){
		for(int j = 0; j < k; j++){
			bfs(arr, q[j], j + 1);
		}
	}
	
	cout << arr[x - 1][y - 1];
	
	return 0;
}