#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dl[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 0, 1, 0};
int dc[] = {0, 0, 0, 1, 0, -1};

int bfs(vector<vector<string>>& arr, int s_l, int s_r, int s_c){
	
	int l = arr.size();
	int r = arr[0].size();
	int c = arr[0][0].size();
	
	vector<vector<vector<bool>>> visited(l, vector<vector<bool>>(r, vector<bool>(c, false)));
	visited[s_l][s_r][s_c] = true;
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(0, s_l), make_pair(s_r, s_c)));
	
	while(!q.empty()){
		int cnt = q.front().first.first;
		int curr_l = q.front().first.second;
		int curr_r = q.front().second.first;
		int curr_c = q.front().second.second;
		q.pop();
		if(arr[curr_l][curr_r][curr_c] == 'E'){
			return cnt;
		}
		for(int i = 0; i < 6; i++){
			int next_l = curr_l + dl[i];
			int next_r = curr_r + dr[i];
			int next_c = curr_c + dc[i];
			if(next_l < 0 or next_l >= l or next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
				continue;
			}
			if(!visited[next_l][next_r][next_c] and arr[next_l][next_r][next_c] != '#'){
				visited[next_l][next_r][next_c] = true;
				q.push(make_pair(make_pair(cnt + 1, next_l), make_pair(next_r, next_c)));
			}
		}
	}
	
	return -1;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int l, r, c;
		cin >> l >> r >> c;
		if(l == 0){
			break;
		}
		vector<vector<string>> arr(l, vector<string>(r));
		int s_l, s_r, s_c;
		int e_l, e_r, e_c;
		
		for(int i = 0; i < l; i++){
			for(int j = 0; j < r; j++){
				cin >> arr[i][j];
				for(int k = 0; k < c; k++){
					if(arr[i][j][k] == 'S'){
						s_l = i;
						s_r = j;
						s_c = k;
					}
				}
			}
		}
		
		int answer = bfs(arr, s_l, s_r, s_c);
		
		if(answer == -1){
			cout << "Trapped!\n";	
		}else{
			cout << "Escaped in " << answer << " minute(s).\n";
		}
	}
	return 0;
}