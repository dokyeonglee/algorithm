#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int mod = 1e9 + 7;
	
	int n;
	cin >> n;
	
	vector<long long> d(n + 1);
	d[2] = 1;
	
	for(int i = 3; i <= n; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % mod;
	}
	
	long long fac = 1;
	for(int i = 2; i <= n; i++){
		fac = fac * i % mod;
	}
	
	cout << fac * d[n] % mod;
	
	return 0;
}