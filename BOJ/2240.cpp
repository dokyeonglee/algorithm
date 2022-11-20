#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T, W;
	cin >> T >> W;
	
	vector<int> arr(T + 1);
	for(int i = 1; i <= T; i++){
		cin >> arr[i];
	}
	
	vector<vector<vector<int>>> dp(T + 1, vector<vector<int>>(W + 1, vector<int>(2)));
	for(int w = 0; w <= W; w++){
		for(int t = 1; t <= T; t++){
			if(w == 0){
				dp[t][w][0] = dp[t - 1][w][0] + (arr[t] == 1);
			}else{
				dp[t][w][0] = max(dp[t - 1][w][0], dp[t - 1][w - 1][1]) + (arr[t] == 1);
				dp[t][w][1] = max(dp[t - 1][w][1], dp[t - 1][w - 1][0]) + (arr[t] == 2);
			}
		}
	}
	
	int answer = 0;
	for(int i = 0; i < 2; i++){
		for(int j = 1; j <= W; j++){
			answer = max(dp[T][j][0], dp[T][j][1]);
		}
	}
	
	cout << answer;
	
	return 0;
}