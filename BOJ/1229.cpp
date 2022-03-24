#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> hexa(1001);
	for(int i = 1; i <= 1000; i++){
		hexa[i] = i * (2 * i - 1);
	}
	
	int n;
	cin >> n;

	vector<int> dp(1000001, 987654321);
	dp[0] = 0;
	
	for(int i = 1; hexa[i] <= n; i++){
		for(int j = hexa[i]; j <= n; j++){
			dp[j] = min(dp[j], dp[j - hexa[i]] + 1);
		}
	}
	
	cout << dp[n];
	
	return 0;
}