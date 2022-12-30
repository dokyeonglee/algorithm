#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
	
		vector<int> arr(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> arr[i];
			arr[i] += arr[i - 1];
		}
		
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for(int l = 2; l <= n; l++){
			for(int i = 1; i <= n - (l - 1); i++){
				dp[i][i + l - 1] = 987654321;
				for(int j = i; j <= i + l - 2; j++){
					dp[i][i + l - 1] = min(dp[i][i + l - 1], dp[i][j] + dp[j + 1][i + l - 1] + arr[i + l - 1] - arr[i - 1]);
				}
			}
		}
		
		cout << dp[1][n] << "\n";
		
	}
	
	return 0;
}