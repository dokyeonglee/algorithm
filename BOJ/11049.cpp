#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> p(n + 1);
	cin >> p[0] >> p[1];
	for(int i = 2; i <= n; i++){
		int r, c;
		cin >> r >> c;
		p[i] = c;
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	
	for(int l = 2; l <= n; l++){
		for(int i = 1; i <= n - (l - 1); i++){
			int j = i + l - 1;
			dp[i][j] = 987654321;
			for(int k = i; k <= j - 1; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]);
			}
		}
	}
	
	cout << dp[1][n] << endl;
	return 0;
}
