#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1e9 + 7;

long long pow(long long a, long long n){
	if(n == 1){
		return a;
	}
	long long result = pow(a, n / 2);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> fac(10001, 1);
	for(int i = 2; i <= 10000; i++){
		fac[i] = fac[i - 1] * i % mod;
	}
	
	int T;
	cin >> T;
	
	while(T--){
		int l;
		cin >> l;
		if(l % 2 == 1){
			cout << "0\n";
		}else{
			long long answer = fac[l] * pow(pow(fac[l / 2], mod - 2), 2) % mod;
			answer = answer * pow(l / 2 + 1, mod - 2) % mod;
			cout << answer << "\n";
		}
	}
	
	return 0;
}