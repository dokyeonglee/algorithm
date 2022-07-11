#include <iostream>
using namespace std;

int main() {
	
	long long n;
	cin >> n;
	
	long long answer = 0;
	long long k = 0;
	for(long long i = 1; i * i <= n; i++){
		answer += n / i * 2;
		k = i;
	}
	
	cout << answer - k * k;
	
	return 0;
}