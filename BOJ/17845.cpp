#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> arr(k + 1);
	for(int i = 1; i <= k; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	vector<vector<int>> dp(k + 1, vector<int>(n + 1));
	
	for(int i = 1; i <= k; i++){
		for(int j = 0; j <= n; j++){
			if(j >= arr[i].second){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].second] + arr[i].first);
			}else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	cout << dp[k][n];
	
	return 0;
}