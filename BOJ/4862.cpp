#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

map<long long, long long> phi;

long long euler_phi(long long n){
	
	if(phi.count(n)){
		return phi[n];
	}
	
	long long result = n;
	long long temp = n;
	
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			result = result - result / i;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	return phi[temp] = (n == 1 ? result : result - result / n);
}

long long mod(long long x, long long p){
	return x >= p ? x % p + p : x;
}

long long pow(long long a, long long n, long long m){

	int check = 0;

	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, m);
	if(result * result >= m){
		check = 1;
	}
	result = result * result % m;
	if(n % 2 == 1){
		if(result * a >= m){
			check = 1;
		}
		result = result * a % m;
	}
	return result + m * check;
}

long long solve(long long n, long long idx, long long m){
	if(idx == 1 or m == 1){
		return mod(n, m);
	}
	return pow(n, solve(n, idx - 1, euler_phi(m)), m);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int ten_pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
	
	while(1){
		int b;
		cin >> b;
		if(b == 0){
			break;
		}
		
		int i, n;
		cin >> i >> n;
		
		int m = ten_pow[n];
		
		cout << setfill('0') << setw(n) << solve(b, i, m) % m << "\n";
	}
	
	return 0;
}