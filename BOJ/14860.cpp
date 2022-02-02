#include <iostream>
#include <vector>

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

int main() {
	
	vector<bool> is_prime(15000001, true);
	is_prime[0] = is_prime[1] = false;
	
	for(long long i = 2; i * i <= 15000000; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 15000000; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	long long n, m;
	cin >> n >> m;
	
	long long answer = 1;
	long long mod = 1e9 + 7;
	long long _min = min(n, m);
	for(int i = 2; i <= _min; i++){
		if(is_prime[i]){
			long long temp = i;
			while(temp <= _min){
				answer = answer * pow(i, (n / temp) * (m / temp), mod) % mod;
				temp *= i;
			}
		}
	}
		
	cout << answer;
	
	return 0;
}