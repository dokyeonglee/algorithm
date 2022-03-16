#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<long long> dp(n + 5, 1);
	vector<long long> dp2(n + 5, 1);

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	}
	
	dp2[2] = 3;
	for(int i = 4; i <= n; i++){
		dp2[i] = dp2[i - 2] + 2 * dp2[i - 4];	
	}
	
	cout << dp[n] - (dp[n] - dp2[n]) / 2;
		
	return 0;
}