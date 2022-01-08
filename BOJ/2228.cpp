#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	
	for(int i = 1; i <= m; i++){
		dp[0][i] = -987654321;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j];
			for(int k = 1; k <= i; k++){
				if(k >= 2){
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + arr[i] - arr[k - 1]);
				}else if(k == 1 and j == 1){
					dp[i][j] = max(dp[i][j], arr[i]);
				}
			}
		}
	}
	
	cout << dp[n][m];
	
	return 0;
}