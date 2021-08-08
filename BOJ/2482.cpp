#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	
	for(int i = 1; i <= n; i++){
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= k; j++){
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
		}
	}
	
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % 1000000003;
	
	return 0;
}