#include <iostream>
using namespace std;

pair<long long, pair<long long, long long>> gcd(long long a, long long b){
	if(b == 0){
		return make_pair(a, make_pair(1, 0));
	}
	pair<long long, pair<long long, long long>> result = gcd(b, a % b);
	long long g, x, y;
	g = result.first;
	x = result.second.first;
	y = result.second.second;
	return make_pair(g, make_pair(y, x - (a / b) * y));
}

long long inv(long long a, long long m){
	auto result = gcd(a, m);
	if(result.first > 1){
		return -1;
	}
	return (result.second.first + m) % m;
}

long long phi(long long n){
	long long result = n;
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
			}
			result -= result / i;
		}
	}
	if(n > 1){
		result -= result / n;
	}
	return result;
}

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
	
	long long n, e, c;
	cin >> n >> e >> c;
	long long d = inv(e, phi(n));
	cout << pow(c, d, n);
	
	return 0;
}