#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<vector<long long>>& dp, int n, int k){
	if(n == 0){
		return k == 0;
	}
	if(k == 0){
		return 1ll << n;
	}
	long long& ret = dp[n][k];
	if(ret != -1){
		return ret;
	}
	return ret = solve(dp, n - 1, k + 1) + solve(dp, n - 1, k - 1);
}

int main() {
	
	int k, n;
	cin >> k >> n;
	
	vector<vector<long long>> dp(n + 1, vector<long long>(n + k + 1, -1));
	cout << (1ll << n) - solve(dp, n, k);
		
	return 0;
}