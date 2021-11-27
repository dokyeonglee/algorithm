#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int>& arr, vector<vector<int>>& dp, int i, int j){
	
	if(i > j){
		return 0;
	}else if(i == j){
		return 1;
	}
	
	int& ret = dp[i][j];
	
	if(ret != -1){
		return dp[i][j];
	}
	
	ret = 2;
	
	int d = arr[j] - arr[i];
	
	auto it = lower_bound(arr.begin(), arr.end(), arr[j] + d) - arr.begin();
	
	if(arr[it] == arr[j] + d){
		return ret = solve(arr, dp, j, it) + 1;	
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	int answer = 1;
	int cnt = 1;
	
	for(int i = 1; i <= n; i++){
		if(arr[i] == arr[i - 1]){
			cnt++;
			answer = max(answer, cnt);
		}else{
			cnt = 1;
		}
	}
	
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));
	
	for(int i = 0; i < arr.size(); i++){
		for(int j = i + 1; j < arr.size(); j++){
			answer = max(answer, solve(arr, dp, i, j));
		}
	}
	
	cout << answer;
		
	return 0;
}