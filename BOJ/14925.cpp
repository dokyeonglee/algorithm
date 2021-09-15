#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n;
	cin >> m >> n;
	
	vector<vector<int>> arr(m + 1, vector<int>(n + 1, -1));
	vector<vector<int>> dp(arr);
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(arr[i][j] == 0){
				if(arr[i - 1][j - 1] == 0 and arr[i - 1][j] == 0 and arr[i][j - 1] == 0){
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}else{
					dp[i][j] = 1;
				}
			}else{
				dp[i][j] = 0;
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			answer = max(answer, dp[i][j]);
		}
	}
	
	cout << answer;
	
	return 0;
}