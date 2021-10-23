#include <iostream>
#include <cmath>

using namespace std;

const int mod = 10000; //문제 좀 잘 읽자. '십만' 아니고 '만' 이다.

long long pow(long long a, long long b){
	
	if(b == 0){
		return 1;
	}
	
	long long temp = pow(a, b / 2);
	temp = temp * temp % mod;
	
	if(b % 2 == 1){
		temp = temp * a % mod;
	}
	
	return temp;
	
}

int main() {
	
	long long n;
	cin >> n;
	
	long long d = log10(n);
	long long t = pow(10, d);
	
	long long l = (9 * d * t - t + 1) / 9 + (n - t + 1) * (d + 1);
	
	long long answer = n % mod * pow(2ll, n - 1) + pow(2ll, n) - 4 + 3 * n % mod + (pow(2ll, n - 1) + 1) * (l % mod) % mod;
	cout << answer % mod;
	
	return 0;
}