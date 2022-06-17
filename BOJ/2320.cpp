#include <iostream>
#include <vector>

using namespace std;

int solve(vector<string>& arr, vector<vector<int>>& dp, int bit, char last){
	
	if(bit == (1 << arr.size()) - 1){
		return 0;
	}
	
	int& ret = dp[bit][last - 'A'];
	
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	
	for(int i = 0; i < arr.size(); i++){
		if((bit & (1 << i)) == 0){
			if(bit == 0 or last == arr[i].front()){
				ret = max(ret, solve(arr, dp, bit | (1 << i), arr[i].back()) + (int)arr[i].size());
			}
		}
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(1 << n, vector<int>(26, -1));
	vector<string> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	cout << solve(arr, dp, 0, 'Z');
	
	return 0;
}