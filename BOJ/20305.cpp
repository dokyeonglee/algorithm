#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<long long> fib(n + 2);
	fib[1] = 1;
	
	for(int i = 2; i <= n + 1; i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
	
	vector<long long> answer(n + 5);
	
	while(q--){
		int l, r;
		cin >> l >> r;
		answer[l] = (answer[l] + fib[1]) % mod;
		answer[l + 1] = (answer[l + 1] + fib[2] - fib[1]) % mod;
		answer[r + 1] = (answer[r + 1] - fib[r - l + 2] + mod) % mod;
		answer[r + 2] = (answer[r + 2] - fib[r - l + 1] + mod) % mod;
	}
	
	cout << answer[1] << " ";
	for(int i = 2; i <= n; i++){
		answer[i] = (answer[i] + answer[i - 1] + answer[i - 2]) % mod;
		cout << answer[i] << " ";
	}
	
	return 0;
}