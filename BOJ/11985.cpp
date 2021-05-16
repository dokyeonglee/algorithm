#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<long long> arr(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<long long> dp(n + 1, 1e15);
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
		long long min_size = arr[i];
		long long max_size = arr[i];
		for(int j = i; j >= max(1, i - m + 1); j--){
			min_size = min(min_size, arr[j]);
			max_size = max(max_size, arr[j]);
			dp[i] = min(dp[i], dp[j - 1] + k + (i - j + 1) * (max_size - min_size));
		}
	}
	
	cout << dp[n];
	
	return 0;
}