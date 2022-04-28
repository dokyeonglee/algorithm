#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(m));
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;
	
	int cnt1 = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			if(arr[i][j] == 1){
				cnt1++;
				q1.push(make_pair(i, j));
			}else if(arr[i][j] == 2){
				cnt2++;
				q2.push(make_pair(i, j));
			}
		}
	}
	
	int t = 1;
	while(!q1.empty() or !q2.empty()){
		t++;
		int sz1 = q1.size();
		int sz2 = q2.size();
		for(int i = 0; i < sz1; i++){
			pair<int, int> now = q1.front();
			q1.pop();
			if(arr[now.first][now.second] == 3){
				cnt1--;
				continue;
			}
			for(int j = 0; j < 4; j++){
				int next_r = now.first + dr[j];
				int next_c = now.second + dc[j];
				if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
					continue;
				}
				if(arr[next_r][next_c] == 0){
					arr[next_r][next_c] = 2 * t + 1;
					q1.push(make_pair(next_r, next_c));
					cnt1++;
				}
			}
		}
		
		for(int i = 0; i < sz2; i++){
			pair<int, int> now = q2.front();
			q2.pop();
			for(int j = 0; j < 4; j++){
				int next_r = now.first + dr[j];
				int next_c = now.second + dc[j];
				if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
					continue;
				}
				if(arr[next_r][next_c] == 0){
					arr[next_r][next_c] = 2;
					q2.push(make_pair(next_r, next_c));
					cnt2++;
				}else if(arr[next_r][next_c] == 2 * t + 1){
					arr[next_r][next_c] = 3;
					cnt3++;
				}
			}
		}
	}
	
	cout << cnt1 << " " << cnt2 << " " << cnt3;
	
	return 0;
}