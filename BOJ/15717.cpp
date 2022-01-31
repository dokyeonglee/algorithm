#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

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
	
	long long n;
	cin >> n;
	
	cout << pow(2, n - 1);
	
	return 0;
}