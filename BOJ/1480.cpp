#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solve(vector<int>& arr, vector<vector<vector<int>>>& dp, int idx, int visited, int c){
	
	if(idx == dp.size()){
		return __builtin_popcount(visited);
	}
	
	int& ret = dp[idx][visited][c];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	
	for(int i = 0; i < arr.size(); i++){
		if(visited & (1 << i)){
			continue;
		}
		if(c >= arr[i]){
			ret = max(ret, solve(arr, dp, idx, visited | (1 << i), c - arr[i]));
		}
	}
	
	ret = max(ret, solve(arr, dp, idx + 1, visited, dp[0][0].size() - 1));
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, c;
	cin >> n >> m >> c;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<vector<vector<int>>> dp(m, vector<vector<int>>(1 << n, vector<int>(c + 1, -1)));
	
	cout << solve(arr, dp, 0, 0, c);
	
	return 0;
}