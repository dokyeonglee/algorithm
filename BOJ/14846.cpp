#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int dp[n + 1][n + 1][11] = {0};
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			dp[i][j][x]++;
			for(int y = 1; y <= 10; y++){
				dp[i][j][y] += dp[i - 1][j][y] + dp[i][j - 1][y] - dp[i - 1][j - 1][y];
			}
		}
	}
	
	int q;
	cin >> q;
	
	for(int i = 0; i < q; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = 0;
		for(int j = 1; j <= 10; j++){
			if(dp[x2][y2][j] - dp[x1 - 1][y2][j] - dp[x2][y1 - 1][j] + dp[x1 - 1][y1 - 1][j]){
				answer++;
			}
		}
		cout << answer << "\n";
	}
	
	return 0;
}