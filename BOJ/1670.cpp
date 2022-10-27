#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	n /= 2;
	
	vector<long long> dp(n + 1);
	dp[0] = 1;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i - 1; j++){
			dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j])) % 987654321;
		}
	}
	
	cout << dp[n];
	
	return 0;
}