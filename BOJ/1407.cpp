#include <iostream>

using namespace std;

long long solve(long long n){
	long long result = 0;
	long long p = 1;
	while(n > 0){
		result += (n / 2 + n % 2) * p;
		n /= 2;
		p *= 2;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long a, b;
	cin >> a >> b;
	
	cout << solve(b) - solve(a - 1);
	
	return 0;
}