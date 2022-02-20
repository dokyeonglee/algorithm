#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<long long>> arr(n + 1, vector<long long>(4));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> arr[i][j];
		}
	}
	
	vector<vector<long long>> dp(n + 1, vector<long long>(8));
	
	dp[1][3] = abs(arr[1][1] - arr[1][2]);
	dp[1][6] = abs(arr[1][2] - arr[1][3]);

	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][6] + abs(arr[i][1] - arr[i - 1][1]);
		dp[i][2] = dp[i - 1][5] + abs(arr[i][2] - arr[i - 1][2]);
		dp[i][3] = max(dp[i - 1][4] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i - 1][2]), dp[i - 1][7] + abs(arr[i][1] - arr[i][2]));
		dp[i][4] = dp[i - 1][3] + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][5] = dp[i - 1][2] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][6] = max(dp[i - 1][1] + abs(arr[i][2] - arr[i - 1][2]) + abs(arr[i][3] - arr[i - 1][3]), dp[i - 1][7] + abs(arr[i][2] - arr[i][3]));
		dp[i][7] = dp[i - 1][0] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i - 1][2]) + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][7] = max(dp[i][7], dp[i - 1][6] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i][3]));
		dp[i][7] = max(dp[i][7], dp[i - 1][3] + abs(arr[i][3] - arr[i - 1][3]) + abs(arr[i][1] - arr[i][2]));
	}

	cout << dp[n][7] << "\n";
	
	for(int i = 2; i <= n; i++){
		fill(dp[i].begin(), dp[i].end(), 1e18);
	}
	
	for(int i = 2; i <= n; i++){
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][6] + abs(arr[i][1] - arr[i - 1][1]);
		dp[i][2] = dp[i - 1][5] + abs(arr[i][2] - arr[i - 1][2]);
		dp[i][3] = min(dp[i - 1][4] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i - 1][2]), dp[i - 1][7] + abs(arr[i][1] - arr[i][2]));
		dp[i][4] = dp[i - 1][3] + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][5] = dp[i - 1][2] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][6] = min(dp[i - 1][1] + abs(arr[i][2] - arr[i - 1][2]) + abs(arr[i][3] - arr[i - 1][3]), dp[i - 1][7] + abs(arr[i][2] - arr[i][3]));
		dp[i][7] = dp[i - 1][0] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i - 1][2]) + abs(arr[i][3] - arr[i - 1][3]);
		dp[i][7] = min(dp[i][7], dp[i - 1][6] + abs(arr[i][1] - arr[i - 1][1]) + abs(arr[i][2] - arr[i][3]));
		dp[i][7] = min(dp[i][7], dp[i - 1][3] + abs(arr[i][3] - arr[i - 1][3]) + abs(arr[i][1] - arr[i][2]));
	}
	
	cout << dp[n][7];
	
	return 0;
}