#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n, m;
		cin >> n >> m;
		
		if(n == 0 and m == 0){
			break;
		}
		
		vector<vector<int>> arr(n + 1, vector<int>(m + 1));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> arr[i][j];
			}
		}
		
		vector<vector<int>> dp(arr);
		int answer = 0;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(arr[i][j] == 1){
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				}else{
					dp[i][j] = 0;
				}
				answer = max(answer, dp[i][j]);
			}
		}
		
		cout << answer << "\n";
	}

	return 0;
}