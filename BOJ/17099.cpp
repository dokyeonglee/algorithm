#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, int>> arr(n + 1);
	
	for(int i = 1; i <= n; i++){
		int s, e, c;
		cin >> s >> e >>c;
		arr[i] = make_pair(make_pair(e, s), c);
	}
	
	sort(arr.begin(), arr.end());
	
	vector<int> dp(n + 1);
	
	for(int i = 1; i <= n; i++){
		pair<pair<int, int>, int> p = make_pair(make_pair(arr[i].first.second, 0), 0);
		int pos = lower_bound(arr.begin() + 1, arr.end(), p) - arr.begin() - 1;
		dp[i] = max(dp[i - 1], dp[pos] + arr[i].second);
	}
	
	cout << dp[n];
	
	return 0;
}