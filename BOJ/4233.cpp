#include <iostream>
using namespace std;

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

bool is_prime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

bool fake_prime(int a, int p){
	return !is_prime(p) and pow(a, p, p) == a % p;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int p, a;
		cin >> p >> a;
		if(p == 0){
			break;
		}
		if(fake_prime(a, p)){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}
	
	return 0;
}