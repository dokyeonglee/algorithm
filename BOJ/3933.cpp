#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<long long>> dp(1 << 15, vector<long long>(4));
	
	for(int i = 1; i * i < (1 << 15); i++){
		dp[i * i][0] = 1;
		for(int j = i * i; j < (1 << 15); j++){
			dp[j][1] += dp[j - i * i][0];
			dp[j][2] += dp[j - i * i][1];
			dp[j][3] += dp[j - i * i][2];
		}
	}
	
	while(1){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		
		cout << dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}
	
	return 0;
}