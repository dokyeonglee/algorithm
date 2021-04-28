#include <iostream>
using namespace std;

const int MOD = 1000000007;

void mul(long long A[2][2], long long B[2][2]){
	
	long long x = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
	long long y = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
	long long z = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
	long long w = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
	
	A[0][0] = x;
	A[0][1] = y;
	A[1][0] = z;
	A[1][1] = w;
		
}

void pow(long long fib[2][2], long long n){
	
	if(n <= 1){
		return;
	}
		
	pow(fib, n / 2);
	mul(fib, fib);
	
	if(n % 2 == 1){
		long long A[2][2] = {{1, 1}, {1, 0}};
		mul(fib, A);
	}
	
}

int main() {
	
	long long n;
	cin >> n;
	
	long long fib[2][2] = {{1, 1}, {1, 0}};
	
	pow(fib, n - 1);
	
	cout << fib[0][0];
	
	return 0;
}