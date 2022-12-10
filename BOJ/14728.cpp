#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, t;
	cin >> n >> t;
	
	vector<int> time(n + 1);
	vector<int> score(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> time[i] >> score[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(t + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= t; j++){
			if(j < time[i]){
				dp[i][j] = dp[i - 1][j];
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + score[i]);
			}
		}
	}
	
	cout << dp[n][t];
	
	return 0;
}