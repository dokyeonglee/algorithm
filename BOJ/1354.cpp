#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long solve(map<long long, long long>& dp, long long n, long long p, long long q, long long x, long long y){
	if(n <= 0){
		return 1;
	}	
	if(dp[n]){
		return dp[n];
	}
	return dp[n] = solve(dp, n / p - x, p, q, x, y) + solve(dp, n / q - y, p, q, x, y);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, p, q, x, y;
	cin >> n >> p >> q >> x >> y;

	map<long long, long long> dp;
	cout << solve(dp, n, p, q, x, y);
		
	return 0;
}