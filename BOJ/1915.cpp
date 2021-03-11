#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		
		string row;
		cin >> row;
		
		for(int j = 1; j <= m; j++){
		
			if(row[j - 1] - '0' == 1){ 
				
				dp[i][j] = 1;
				
				if(dp[i - 1][j - 1] != 0 and dp[i - 1][j] != 0 and dp[i][j - 1] != 0){
					if(dp[i - 1][j - 1] != 1 and dp[i - 1][j] != 1 and dp[i][j - 1] != 1){
						dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
					}else{
						dp[i][j] = 2;
					}
				}
				
				answer = max(answer, dp[i][j] * dp[i][j]);
				
			}
		}
		
	}
	
	cout << answer;
	
	return 0;
}