#include <iostream>
using namespace std;

long long xor_to_n(long long n){
	if(n % 4 == 0){
		return n;
	}
	if(n % 4 == 1){
		return 1;
	}
	if(n % 4 == 2){
		return n + 1;
	}
	return 0;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		long long s, f;
		cin >> s >> f;
		cout << (xor_to_n(f) ^ xor_to_n(s - 1)) << "\n";
	}
	
	return 0;
}