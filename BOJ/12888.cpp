#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<long long> dp(61);
	dp[0] = 1;
	
	for(int i = 1; i <= 60; i++){
		dp[i] = 2 * dp[i - 1] + 1 - 2 * (i % 2);
	}
	
	int n;
	cin >> n;
	
	cout << dp[n];
	
	return 0;
}