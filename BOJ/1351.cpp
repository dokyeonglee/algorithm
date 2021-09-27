#include <iostream>
#include <map>

using namespace std;

long long solve(map<long long, long long>& dp, long long n, long long p, long long q){
	
	if(n == 0){
		return 1;
	}
	
	long long& ret = dp[n];
	if(ret != 0){
		return ret;	
	}else{
		return ret = solve(dp, n / p, p, q) + solve(dp, n / q, p, q);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, p, q;
	cin >> n >> p >> q;
	
	map<long long, long long> dp;
	cout << solve(dp, n, p, q);
	
	return 0;
}