
#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {

	long long c1, c2, c3, c4, c5, c6;
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	
	long long x1, x2, x3, x4, x5, x6, x7;
	
	x2 = gcd(c1, c5);
	x1 = c1 / x2;
	x3 = c5/ x2;
	x6 = gcd(c3, c6);
	x7 = c3 / x6;
	x5 = c6 / x6;
	
	cout << x1 << " " << x2 << " " << x3 << " " << x5 << " " << x6 << " " << x7;
	
	
	return 0;
}