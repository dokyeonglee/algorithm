#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> dp[i][j];
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	int answer = -987654321;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int ii = i; ii <= n; ii++){
				for(int jj = j; jj <= m; jj++){
					answer = max(answer, dp[ii][jj] - dp[ii][j - 1] - dp[i - 1][jj] + dp[i - 1][j - 1]);
				}
			}
		}
	}
	
	cout << answer;
	
	return 0;
}