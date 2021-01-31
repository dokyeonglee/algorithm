#include <iostream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	long long fib0 = 0, fib1 = 1, fib2 = 1;
	
	for(int i = 0; i < n; i++){
		fib2 = fib0 + fib1;
		fib0 = fib1;
		fib1 = fib2;
	}
	
	cout << 2 * (fib0 + fib1) << '\n';
	
	return 0;
}