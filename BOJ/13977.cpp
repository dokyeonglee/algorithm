#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

long long pow(long long a, long long n, long long p){
	
	if(n == 0){
		return 1;
	}
	
	long long result = pow(a, n / 2, p);
	result = result * result % p;
	
	if(n % 2 == 1){
		result = result * a % p;
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> fac(4000001, 1);
	for(int i = 1; i <= 4000000; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	int M;
	cin >> M ;
	
	while(M--){
		int n, k;
		cin >> n >> k;
		long long answer = fac[n] * pow(fac[k], mod - 2, mod) % mod;
		answer = answer * pow(fac[n - k], mod - 2, mod) % mod;
		cout << answer << "\n";
	}
	
	return 0;
}