#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& dp, int n, int state){
	if(n < 0){
		return 0;
	}
	if(n == 0){
		return state == 0;
	}
	int& ret = dp[n][state];
	if(ret != -1){
		return ret;
	}
	if(state == 0){
		ret = solve(dp, n - 1, 0) + solve(dp, n - 2, 0) + 2 * solve(dp, n - 1, 1) + solve(dp, n - 1, 3);
	}else if(state == 1){
		ret = solve(dp, n - 1, 0) + solve(dp, n - 1, 1);
	}else if(state == 2){
		ret = solve(dp, n - 1, 3);	
	}else if(state == 3){
		ret = solve(dp, n - 1, 0) + solve(dp, n - 1, 2);
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	vector<vector<int>> dp(501, vector<int>(4, -1));
	
	while(T--){
		int n;
		cin >> n;
		cout << solve(dp, n, 0) << "\n";
	}
	
	return 0;
}