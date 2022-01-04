#include <iostream>
using namespace std;

long long euler_phi(long long x){
	long long result = x;
	for(long long p = 2; p * p <= x; p++){
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
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	while(cin >> n){
		cout << euler_phi(n) / 2 << "\n";
	}
	
	return 0;
}