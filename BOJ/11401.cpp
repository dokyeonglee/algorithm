#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, mod);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	return result;
}

int main() {
	
	long long mod = 1e9 + 7;
	
	int n, k;
	cin >> n >> k;
	
	k = min(k, n - k);
	
	vector<long long> fac(n + 1, 1);
	for(int i = 2; i <= n; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	
	
	long long answer = fac[n] * pow(fac[k], mod - 2, mod) % mod;
	answer = answer * pow(fac[n - k], mod - 2, mod) % mod;
	cout << answer;
	
	return 0;
}