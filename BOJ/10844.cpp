#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(10, vector<int>(n + 1));
	
	const int mod = 1e9;
	
	for(int i = 1; i <= 9; i++){
		dp[i][0] = 1;
		dp[i][1] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		
		dp[1][i] += dp[1][i - 2];
		dp[1][i] += dp[2][i - 1];
		dp[1][i] %= mod;
		
		for(int j = 2; j <= 8; j++){
			dp[j][i] += dp[j - 1][i - 1];
			dp[j][i] += dp[j + 1][i - 1];
			dp[j][i] %= mod;
		}
		
		dp[9][i] += dp[8][i - 1];
		dp[9][i] %= mod;
	}
	
	int answer = 0;
	
	for(int i = 1; i <= 9; i++){
		answer = (answer + dp[i][n]) % mod;
	}
	
	cout << answer << endl;
	
	return 0;
}