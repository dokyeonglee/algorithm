#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 10000003;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	vector<vector<int>> dp(101, vector<int>(100001));
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		dp[i][arr[i]] = 1;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= 100000; j++){
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			int g = gcd(arr[i], j);
			dp[i][g] += dp[i - 1][j];
			dp[i][g] %= mod;
		}
	}
	
	cout << dp[n - 1][1];
	
	return 0;
}