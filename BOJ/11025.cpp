#include <iostream>

using namespace std;

int main() {
	
	long long n, k;
	cin >> n >> k;
	
	long long answer = 0;
	for(int i = 1; i <= n; i++){
		answer = (answer + k) % i;
	}
	cout << answer + 1;
	
	return 0;
}