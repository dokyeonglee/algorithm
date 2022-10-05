#include <iostream>
using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int a, b;
		cin >> a >> b;
		if(a == 1){
			cout << b << "\n";
			continue;
		}
		while(a > 1){
			int x = b / a + 1;
			a = a * x - b;
			b *= x;
			int g = gcd(a, b);
			a /= g;
			b /= g;
		}
		cout << b << "\n";
	}
	
	return 0;
}