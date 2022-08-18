#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<int> dp(n + 1);
	
	for(int i = 0; i < n; i++){
		int _max = arr[i];
		int _min = arr[i];
		for(int j = i; j >= 0; j--){
			_max = max(_max, arr[j]);
			_min = min(_min, arr[j]);
			dp[i + 1] = max(dp[i + 1], dp[j] + _max - _min);
		}
	}
	
	cout << dp[n];
	
	return 0;
}