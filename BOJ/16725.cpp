#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 9;

long long pow(long long a, long long n, long long m){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, m);
	result = result * result % m;
	if(n % 2 == 1){
		result = result * a % m;
	}
	return result;
}

int main() {
	
	vector<long long> fac(260001, 1);
	for(int i = 1; i <= 260000; i++){
		fac[i] = i * fac[i - 1] % mod;
	}
	
	long long n, m, k;
	cin >> n >> m >> k;

	long long answer = 0;
	int sign = 1;
	for(int i = 0; i <= k / (n + 1); i++){
		long long temp = fac[m] * pow(fac[i], mod - 2, mod) % mod;
		temp = temp * pow(fac[m - i], mod - 2, mod) % mod;
		temp = temp * fac[m + k - i * (n + 1) - 1] % mod;
		temp = temp * pow(fac[m - 1], mod - 2, mod) % mod;
		temp = temp * pow(fac[k - i * (n + 1)], mod - 2, mod) % mod;
		answer = (answer + sign * temp + mod) % mod;
		sign = -sign;
	}
	
	cout << answer;
	
	return 0;
}