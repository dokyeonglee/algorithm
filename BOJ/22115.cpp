#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 987654321));
	dp[0][0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(j >= arr[i]){
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - arr[i]] + 1);
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	if(dp[n][k] == 987654321){
		cout << -1;
	}else{
		cout << dp[n][k];
	}
	
	return 0;
}