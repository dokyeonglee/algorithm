#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> board(3);
	cin >> board[0] >> board[1] >> board[2];
	
	vector<int> max_dp(3);
	vector<int> min_dp(3);
	
	max_dp[0] = min_dp[0] = board[0];
	max_dp[1] = min_dp[1] = board[1];
	max_dp[2] = min_dp[2] = board[2];
	
	vector<int> temp(3);
	
	for(int i = 1; i < n; i++){
		
		cin >> board[0] >> board[1] >> board[2];
		
		temp[0] = max(max_dp[0], max_dp[1]) + board[0];
		temp[1] = max(max_dp[0], max(max_dp[1], max_dp[2])) + board[1];
		temp[2] = max(max_dp[1], max_dp[2]) + board[2];
		
		max_dp[0] = temp[0];
		max_dp[1] = temp[1];
		max_dp[2] = temp[2];
		
		temp[0] = min(min_dp[0], min_dp[1]) + board[0];
		temp[1] = min(min_dp[0], min(min_dp[1], min_dp[2])) + board[1];
		temp[2] = min(min_dp[1], min_dp[2]) + board[2];
		
		min_dp[0] = temp[0];
		min_dp[1] = temp[1];
		min_dp[2] = temp[2];
	}
	
	cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " " << min(min_dp[0], min(min_dp[1], min_dp[2]));
	
	return 0;
}