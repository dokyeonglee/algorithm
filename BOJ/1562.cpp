#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(12, vector<int>(1 << 10)));
	
	for(int i = 2; i <= 10; i++){
		dp[1][i][1 << (i - 1)] = 1;
	}
	
	const int mod = 1e9;
		
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= 10; j++){
			for(int k = 0; k < (1 << 10); k++){
				dp[i][j][k | (1 << (j - 1))] = (dp[i][j][k | (1 << (j - 1))] + dp[i - 1][j - 1][k]) % mod;
				dp[i][j][k | (1 << (j - 1))] = (dp[i][j][k | (1 << (j - 1))] + dp[i - 1][j + 1][k]) % mod;
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= 10; i++){
		answer = (answer + dp[n][i][(1 << 10) - 1]) % mod;
	}
	
	cout << answer;
	
	return 0;
}