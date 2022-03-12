#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> arr(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
		
	vector<vector<int>> dp(n + 1, vector<int>(1 << n, 987654321));
	fill(dp[0].begin(), dp[0].end(), 0);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < (1 << n); j++){
			if(__builtin_popcount(j) != i - 1){
				continue;
			}
			for(int k = 0; k < n; k++){
				if((j & (1 << k)) == 0){
					dp[i][j | (1 << k)] = min(dp[i][j | (1 << k)], dp[i - 1][j] + arr[i][k + 1]);	
				}
			}
		}
	}
	
	cout << dp[n][(1 << n) - 1];
	
	return 0;
}