#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& dp, int n, int k){

	if(n < k){
		return 0;
	}
	
	if(n == 1 or k == 1){
		return 1;
	}
	
	int& ret = dp[n][k];
	if(ret != -1){
		return ret;
	}
	
	return ret = solve(dp, n - k, k) + solve(dp, n - 1, k - 1);
	
}

int main() {
	
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));
	
	cout << solve(dp, n, k);
	
	return 0;
}