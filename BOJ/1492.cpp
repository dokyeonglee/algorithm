#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;
vector<long long> fac(52, 1);

long long pow(long long a, long long n){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n /2);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	
	result = ((result % mod) + mod) % mod;
	
	return result;
}

long long comb(long long n, long long r){
	long long result = fac[n] * pow(fac[r], mod - 2) % mod;
	return result * pow(fac[n - r], mod - 2) % mod;
}

long long solve(vector<long long>& dp, long long n, int k){
	
	if(k == 1){
		return (n + 1) * n / 2 % mod;
	}
	
	long long& ret = dp[k];
	
	if(ret != -1){
		return ret;
	}
	
	long long result = pow(n + 1, k + 1) - 1;
	for(int i = 0; i < k; i++){
		result -= comb(k + 1, i) * solve(dp, n, i) % mod;
		result = (result % mod + mod) % mod;
	}
	
	return ret = result * pow(k + 1, mod - 2) % mod;
	
}

int main() {
	
	for(int i = 2; i <= 51; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	int n, k;
	cin >> n >> k;
	
	vector<long long> dp(k + 1, -1);
	cout << solve(dp, n, k);
	
	return 0;
}