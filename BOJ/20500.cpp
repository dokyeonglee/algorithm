#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(n + 1, vector<int>(3));
	dp[1][1] = 1;
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
	}
	
	cout << dp[n][0];
	
	return 0;
}