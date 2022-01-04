#include <iostream>
using namespace std;

long long euler_phi(long long x){
	long long result = x;
	for(int p = 2; p * p <= x; p++){
		if(x % p == 0){
			while(x % p == 0){
				x /= p;
			}
			result = result * (p - 1) / p;
		}
	}
	return x == 1 ? result : result * (x - 1) / x;
}

int main() {
	
	long long n;
	cin >> n;
	
	long long answer = 1987654321;
	for(long long i = 1; i * i <= n; i++){
		if(n % i == 0){
			if(euler_phi(i) == n / i){
				answer = min(answer, i);
			}
			if(euler_phi(n / i) == i){
				answer = min(answer, n / i);
			}
		}
	}
	
	if(answer == 1987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}