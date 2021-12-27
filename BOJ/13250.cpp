#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<double> dp(max(n + 1, 6));
	dp[1] = 1;
	dp[2] = (dp[0] + dp[1]) / 6 + 1;
	dp[3] = (dp[0] + dp[1] + dp[2]) / 6 + 1;
	dp[4] = (dp[0] + dp[1] + dp[2] + dp[3]) / 6 + 1;
	dp[5] = (dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) / 6 + 1;
	
	for(int i = 6; i <= n; i++){
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5] + dp[i - 6]) / 6 + 1;
	}
	
	cout << fixed;
	cout.precision(10);
	cout << dp[n];
	
	return 0;
}