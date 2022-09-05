#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double solve(vector<pair<int, int>>& arr, vector<vector<double>>& dp, int bit, int m, int c, int r){
	
	if(c == 0){
		return 1;
	}
	
	if(r < c){
		return 0;
	}
		
	double& ret = dp[bit][c];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	for(int i = 0; i < arr.size(); i++){
		if((bit & (1 << i)) == 0 and arr[i].first <= m){
			ret = max(ret, arr[i].second / 100.0 * solve(arr, dp, bit | (1 << i), m - arr[i].first, c - 1, r - 1) + (1 - arr[i].second / 100.0) * solve(arr, dp, bit | (1 << i), m - arr[i].first, c, r - 1));
		}
	}
	
	return ret;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	cout << fixed;
	cout << setprecision(10);

	while(T--){
		int n, c, m;
		cin >> n >> c >> m;
		vector<pair<int, int>> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i].first >> arr[i].second;
		}
		
		if(c > n){
			cout << 0 << "\n";
			continue;
		}else if(c == n){
			double answer = 1;
			int sum = 0;
			for(int i = 0; i < n; i++){
				answer *= arr[i].second / 100.0;
				sum += arr[i].first;
			}
			if(sum > m){
				cout << 0 << "\n";
				continue;
			}
			cout << answer << "\n";
			continue;
		}
		vector<vector<double>> dp(1 << n, vector<double>(n + 1, -1));
		cout << solve(arr, dp, 0, m, c, n) << "\n";
	}
	
	return 0;
}