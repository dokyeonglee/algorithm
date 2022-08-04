#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(2, vector<int>(n + 1, 987654321));
	vector<vector<int>> dp(arr);
	
	dp[1][1] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[1][j];
			if(i != 1 or j != 1) dp[1][j] = min(dp[0][j] + max(arr[1][j] - arr[0][j] + 1, 0), dp[1][j - 1] + max(arr[1][j] - arr[1][j - 1] + 1, 0));
		}
		for(int j = 1; j <= n; j++){
			dp[0][j] = dp[1][j];
			arr[0][j] = arr[1][j];
		}
	}
	
	cout << dp[1][n];

	return 0;
}