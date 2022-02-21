#include <iostream>
#include <vector>

using namespace std;

unsigned long long pow(long long a, long long n){
	if(n == 1){
		return a;
	}
	long long result = pow(a, n / 2);
	result = result * result;
	if(n % 2 == 1){
		result = result * a;
	}
	return result;
}

unsigned long long C(unsigned long long n, unsigned long long r){
	
	if(n == r or r == 0){
		return 1;
	}
	
	r = min(r, n - r);
	
	if(r == 1){
		return n;
	}
	
	unsigned long long result = n;
	for(long long i = 2; i <= r; i++){
		result = (__int128)result * (n - i + 1) / i;
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int t, p, r, c;
		cin >> t >> p >> r >> c;
		cout << t << " " << pow(p, r - c) * C(r, c) << "\n";
	}
	
	
	return 0;
}