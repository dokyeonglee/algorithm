#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

long long pow(long long a, long long n){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r;
	cin >> n >> r;
	
	vector<long long> fac(1000001, 1);
	for(int i = 2; i <= 1000000; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	long long answer = fac[n] * pow(fac[r], mod - 2) % mod;
	answer = answer * pow(fac[n - r], mod - 2) % mod;
	
	cout << answer;
	
	return 0;
}