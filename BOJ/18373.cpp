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
	
	int n, k, p;
	cin >> n >> k >> p;
	
	if(n == 2){
		cout << 2 % p;
	}else if(n == 3 and k == 2){
		cout << 720 % p;
	}else if(n == 3 and k == 3){
		long long answer = 1;
		for(int i = 1; i <= 720; i++){
			answer = answer * i % p;
		}
		cout << answer;
	}else if(k > 2 || n > 12){
		cout << 0;
	}else{
		vector<int> fac(n + 1, 1);
		for(int i = 1; i <= n; i++){
			fac[i] = fac[i - 1] * i;
		}
		if(fac[n] >= p){
			cout << 0;
		}else{
			if(n < 12){
				long long answer = 1;
				for(int i = 1; i <= fac[n]; i++){
					answer = answer * i % p;
				}
				cout << answer;
			}else{
				long long answer = 1;
				for(int i = fac[n] + 1; i < p; i++){
					answer = answer * i % p;
				}
				answer = p - pow(answer, p - 2, p);
				
				cout << answer;
			}
		}
	}
	
	return 0;
}