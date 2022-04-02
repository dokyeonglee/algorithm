#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<vector<long long>> dp(n + 5, vector<long long>(2));
	
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	
	for(int i = 3; i <= n; i++){
		dp[i][1] = (dp[i - 1][1] + dp[i - 3][0]) % 1000000007;
		dp[i][0] = (3 * dp[i - 2][0] + 2 * dp[i - 1][0] + 2 * dp[i][1]) % 1000000007;
	}
	
	cout << dp[n][0];
		
	return 0;
}