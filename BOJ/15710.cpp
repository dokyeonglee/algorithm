#include <iostream>
using namespace std;

long long pow(long long a, long long n, int mod){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, mod);
	result = result * result % mod;
	if(n % 2 == 1){
		result *= a;
		result %= mod;
	}
	return result;
}

int main() {
	
	int a, b, n;
	cin >> a >> b >> n;

	int mod = 1e9 + 7;
	
	cout << pow(1ll << 31, n - 1, mod);
	
	return 0;
}