#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(2 * n + 1, vector<int>(2 * n + 1));
	dp[0][0] = 1;
	
	for(int i = 1; i <= 2 * n; i++){
		dp[i][0] = 1;
		for(int j = 1; j <= i; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	
	cout << dp[2 * (n - 1)][n - 1];
	
	return 0;
}