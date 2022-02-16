#include <iostream>

using namespace std;

long long dp[105][105][105];
long long mod = 1e9 + 7;

int main() {
	
	int n, l, r;
	cin >> n >> l >> r;
	
	dp[1][1][1] = 1;
	dp[2][1][2] = 1;
	dp[2][2][1] = 1;
	
	for(int k = 3; k <= n; k++){
		for(int i = 1; i <= k; i++){
			if(i == k){
				dp[k][i][1] = 1;
				continue;
			}
			for(int j = 1; j <= k; j++){
				if(i == 1 and j == 1){
					continue;
				}
				if(j == k){
					dp[k][1][j] = 1;
					continue;
				}
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