#include <iostream>
#include <vector>

using namespace std;

vector<bool> is_prime(1e6, true);

int solve(vector<vector<int>>& dp, int left, int right){
	
	if(left < 1 or right < 1){
		return 0;
	}
	
	int& ret = dp[left][right];
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	ret = max(ret, max(solve(dp, left - 1, right), solve(dp, left, right - 1)));
	
	int t = 10;
	while(t < right){
		t *= 10;
	}
	int p = left * t + right;
	ret += is_prime[p];
	return ret;
}

int main() {

	is_prime[0] = is_prime[1] = false;
	
	for(int i = 2; i * i < is_prime.size(); i++){
		if(is_prime[i]){
			for(int j = i * i; j < is_prime.size(); j += i){
				is_prime[j] = false;
			}
		}
	}
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	dp[1][1] = 0;
	
	cout << solve(dp, n, n);
	
	return 0;
}