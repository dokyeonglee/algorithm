#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<int>& arr, vector<vector<long long>>& dp, int bit, int last, int k){
	
	if(bit == (1 << arr.size()) - 1){
		return 1;
	}
	
	long long& ret = dp[bit][last];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	
	for(int i = 1; i < arr.size(); i++){
		if((bit & (1 << i)) == 0){
			if(abs(arr[last] - arr[i]) > k){
				ret += solve(arr, dp, bit | (1 << i), i, k);
			}
		}
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(n + 1, 987654321);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	
	vector<vector<long long>> dp(1 << (n + 1), vector<long long>(n + 1, -1));
	
	cout << solve(arr, dp, 1, 0,k);
	
	
	return 0;
}