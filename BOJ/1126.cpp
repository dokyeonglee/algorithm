#include <iostream>
#include <vector>

using namespace std;

long long solve(vector<long long>& arr, vector<vector<long long>>& dp, int idx, long long diff){
	
	if(abs(diff) > 250000){
		return -987654321;
	}
	
	if(idx == arr.size()){
		if(diff == 0){
			return 0;
		}else{
			return -987654321;
		}
	}
	
	long long& ret = dp[idx][diff + 250000];
	if(ret != -1){
		return ret;
	}
	
	ret = solve(arr, dp, idx + 1, diff);
	ret = max(ret, solve(arr, dp, idx + 1, diff + arr[idx]));
	ret = max(ret, solve(arr, dp, idx + 1, abs(diff - arr[idx])) + min(diff, arr[idx]));
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n; 
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	vector<vector<long long>> dp(n, vector<long long>(500001, -1));
	long long answer = solve(arr, dp, 0, 0);
	
	if(answer <= 0){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}