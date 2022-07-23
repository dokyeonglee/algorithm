#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dc[] = {0, 1, 0, -1, -1, 1, -1, 1};

long long dfs(vector<string>& arr, string& str, vector<vector<vector<long long>>>& dp, int r, int c, int idx){
	
	long long& ret = dp[r][c][idx];
	if(ret != -1){
		return ret;
	}
	ret = 0;
	if(idx == str.size() - 1){
		return ret = 1;
	}
	for(int i = 0; i < 8; i++){
		int next_r = r + dr[i];
		int next_c = c + dc[i];
		if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
			continue;
		}
		if(arr[next_r][next_c] == str[idx + 1]){
			ret += dfs(arr, str, dp, next_r, next_c, idx + 1);
		}
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int h, w, l;
	cin >> h >> w >> l;
	
	vector<string> arr(h);
	for(int i = 0; i < h; i++){
		cin >> arr[i];
	}
	
	string str;
	cin >> str;
	
	vector<vector<vector<long long>>> dp(arr.size(), vector<vector<long long>>(arr[0].size(), vector<long long>(str.size(), -1)));
	long long answer = 0;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(str[0] == arr[i][j]){
				answer += dfs(arr, str, dp, i, j, 0);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}