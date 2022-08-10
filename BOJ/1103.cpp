#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


int dfs(vector<vector<int>>& arr, vector<vector<int>>& dp, int r, int c){
	
	if(r < 0 or r >= arr.size() or c < 0 or c >= arr[0].size() or arr[r][c] == -1){
		return 0;
	}
	
	int& ret = dp[r][c];
	if(ret == 0){
		ret = -1;
		int result = 0;
		int temp = 0;
		for(int i = 0; i < 4; i++){
			int next_r = r + dr[i] * arr[r][c];
			int next_c = c + dc[i] * arr[r][c];
			temp = dfs(arr, dp, next_r, next_c);
			if(temp < 0){
				return -1;
			}
			result = max(result, temp);
		}
		ret = result + 1;
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int>(m));
	vector<vector<int>> dp(arr);
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < m; j++){
			if(str[j] == 'H'){
				arr[i][j] = -1;
			}else{
				arr[i][j] = str[j] - '0';
			}
		}
	}
	
	cout << dfs(arr, dp, 0, 0);
	
	
	return 0;
}