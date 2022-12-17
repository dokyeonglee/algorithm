#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> satisfaction(m + 1, vector<int>(n + 1));
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> satisfaction[i][j];
		}
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for(int i = 1; i <= m; i++){
		dp[1][i] = satisfaction[i][1];
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= m; j++){
			for(int k = 1; k <= m; k++){
				int temp = satisfaction[j][i];
				if(j == k){
					temp /= 2;
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + temp);
			}
		}
	}
	
	int answer = 0;
	for(int i = 1; i <= m; i++){
		answer = max(answer, dp[n][i]);
	}
	
	cout << answer;
	
	return 0;
}