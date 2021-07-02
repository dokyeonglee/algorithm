#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0 , -1};

bool bfs(vector<vector<int>>& arr, int L, int R){
	
	int n = arr.size();
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	queue<pair<int, int>> union_q;
	
	bool result = false;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			
			if(!visited[i][j]){
				
				visited[i][j] = true;
				q.push(make_pair(i, j));
				union_q.push(make_pair(i, j));
				
				int sum = arr[i][j];
				
				while(!q.empty()){
					
					pair<int, int> now = q.front();
					q.pop();
					
					for(int k = 0; k < 4; k++){
						
						int next_r = now.first + dr[k];
						int next_c = now.second + dc[k];
						
						if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
							continue;
						}
						
						if(!visited[next_r][next_c]){
							
							int diff = abs(arr[now.first][now.second] - arr[next_r][next_c]);
							
							if(L <= diff and diff <= R){
								
								result = true;
								sum += arr[next_r][next_c];
								visited[next_r][next_c] = true;
								q.push(make_pair(next_r, next_c));
								union_q.push(make_pair(next_r, next_c));
								
							}
						}
					}
				}
				
				int union_size = union_q.size();
				
				while(!union_q.empty()){
					pair<int, int> now = union_q.front();
					union_q.pop();
					arr[now.first][now.second] = sum / union_size;
				}
			}
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l, r;
	cin >> n >> l >> r;
	
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	int answer = 0;
	
	while(bfs(arr, l, r)){
		answer++;
	}
	
	cout << answer;
	
	return 0;
}