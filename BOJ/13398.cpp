#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(n, vector<int>(2));
	
	cin >> dp[0][0];
	dp[0][1] = dp[0][0];
	
	int answer = dp[0][0];
	
	for(int i = 1; i < n; i++){
		int num;
		cin >> num;
		dp[i][0] = max(dp[i - 1][0] + num, num);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + num);
		answer = max(answer, max(dp[i][0], dp[i][1]));
	}
	
	cout << answer;
	
	return 0;
}