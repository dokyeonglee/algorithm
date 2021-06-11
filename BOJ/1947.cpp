#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<long long> dp(max(n + 1, 4));
	
	dp[2] = 1;
	dp[3] = 2;
	
	for(int i = 4; i <= n; i++){
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000000;
	}
	
	cout << dp[n];
	
	return 0;
}