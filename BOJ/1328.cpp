#include <iostream>

using namespace std;

long long dp[105][105][105];
long long mod = 1e9 + 7;

int main() {
	
	int n, l, r;
	cin >> n >> l >> r;
	
	dp[1][1][1] = 1;
	
	for(int k = 2; k <= n; k++){
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= k; j++){
				dp[k][i][j] = dp[k - 1][i][j] * (k - 2)
							+ dp[k - 1][i - 1][j]
							+ dp[k - 1][i][j - 1];
				dp[k][i][j] %= mod;
			}
		}
	}
	
	cout << dp[n][l][r];
		
	return 0;
}