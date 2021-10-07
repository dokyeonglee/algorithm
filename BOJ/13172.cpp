#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

long long pow(long long a, long long b){
	
	if(b == 1){
		return a;
	}
	
	long long temp = pow(a, b / 2);
	temp = temp * temp % mod;
	
	if(b % 2 == 1){
		temp = temp * a % mod;
	}
	
	return temp;
	
}

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m;
	cin >> m;
	
	long long answer = 0;
	
	for(int i = 0; i < m; i++){
		long long a, b;
		cin >> a >> b;
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		answer += b * pow(a, mod - 2) % mod;
		answer %= mod;
	}
	
	cout << answer;	
	
	return 0;
}