#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> fib(n + 2);
	fib[0] = 0;
	fib[1] = 1;
	
	for(int i = 2; i <= n + 1; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= mod;
	}
	
	long long answer = 0;
	for(int i = 1; i <= n; i++){
		answer += fib[gcd(n + 1, i + 1)];
		answer %= mod;
	}
		
	cout << answer;

	return 0;
}