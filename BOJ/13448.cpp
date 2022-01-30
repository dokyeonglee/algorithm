#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using plll = pair<long long, pair<long long, long long>>;
int curr_time;

bool compare(plll& a, plll& b){
	return (double)a.second.second / a.second.first < (double)b.second.second / b.second.first;
}

long long solve(vector<plll>& arr, vector<vector<long long>>& dp, long long idx, long long t, long long T){
	
	int n = dp.size() - 1;
	
	if(idx == n){
		return 0;
	}
	
	long long& ret = dp[idx][t];
	
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	if(idx + 1 <= n and t + arr[idx].second.second <= T){
		ret = max(ret, solve(arr, dp, idx + 1, t + arr[idx].second.second, T) + arr[idx].first - (t + arr[idx].second.second) * arr[idx].second.first);
	}
	if(idx + 1 <= n){
		ret = max(ret, solve(arr, dp, idx + 1, t, T));
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, T;
	cin >> N >> T;
	
	vector<plll> arr(N);
	for(int i = 0; i < N; i++){
		cin >> arr[i].first;
	}
	
	for(int i = 0; i < N; i++){
		cin >> arr[i].second.first;
	}
	
	for(int i = 0; i < N; i++){
		cin >> arr[i].second.second;
	}
	
	sort(arr.begin(), arr.end(), compare);
	
	vector<vector<long long>> dp(N + 1, vector<long long>(T + 1, -1));
	cout << solve(arr, dp, 0, 0, T);
	
	return 0;
}