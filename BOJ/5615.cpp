#include <iostream>

using namespace std;

unsigned long long prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};

unsigned long long pow(unsigned long long a, unsigned long long n, unsigned long long mod){
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

bool miller(unsigned long long n, unsigned long long b, unsigned long long s, unsigned long long t){
	if(n % b == 0){
		return false;
	}
	unsigned long long x = pow(b, t, n);
	if(x == 1 or x == n - 1){
		return true;
	}
	while(s > 1){
		if(x == n - 1){
			return true;
		}
		x = x * x % n;
		s /= 2;
	}
	return false;
}

bool is_prime(unsigned long long n){
	
	if(n == 2){
		return true;
	}
	
	if(n == 1 or n % 2 == 0){
		return false;
	}
	
	unsigned long long s = (n - 1) & -(n - 1);
	unsigned long long t = (n - 1) / s;
	
	for(int i = 0; i < sizeof(prime) / sizeof(unsigned long long); i++){
		long long b = prime[i];
		if(n == b){
			return true;
		}
		if(!miller(n, b, s, t)){
			return false;
		}
	}
	return true;
}
bool ip(unsigned long long n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		unsigned long long x;
		cin >> x;
		if(is_prime(2 * x + 1)){
			answer++;	
		}
		
	}
	
	cout << answer;
	
	return 0;
}