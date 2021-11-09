#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> dp(n + 1);
	vector<long long> arr(n + 1);
	vector<long long> psum(n + 1);
	
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
		dp[i] = dp[i - 1] + arr[i] * sum;
		sum += arr[i];
	}
	
	for(int i = 0; i < q; i++){
		int l, r;
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] - psum[l - 1] * (psum[r] - psum[l - 1]) << "\n";
	}
	
	return 0;
}