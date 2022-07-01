#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	vector<int> dp(n + 1);
	dp[0] = 1;
	
	for(int i = 1; i <= n / 2; i++){
		dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
	}
	
	cout << dp[n / 2];
	
	return 0;
}