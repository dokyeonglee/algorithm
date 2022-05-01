
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& arr, vector<vector<vector<int>>>& dp, int r, int c, int x){
	if(r == arr.size() or c == arr.size()){
		return 0;
	}
	int& ret = dp[x][r][c];
	if(ret != -1){
		return ret;
	}
	
	ret = max(solve(arr, dp, r + 1, c, x), solve(arr, dp, r, c + 1, x)); 
	
	if(arr[r][c] == x){
		ret = max(solve(arr, dp, r + 1, c, (x + 1) % 3) + 1, solve(arr, dp, r, c + 1, (x + 1) % 3) + 1);
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	vector<vector<vector<int>>> dp(3, vector<vector<int>>(n, vector<int>(n, -1)));
	
	cout << solve(arr, dp, 0, 0, 0);
	
	return 0;
}