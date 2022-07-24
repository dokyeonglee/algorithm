#include <iostream>
#include <vector>

using namespace std;

long long pow(long long a, long long n, long long mod){
	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, mod);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long mod = 1e9 + 7;
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<long long>> c(n + 1, vector<long long>(n + 1));
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 or i == j){
				c[i][j] = 1;
			}else{
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			}
		}
	}
	
	cout << c[n][k] * pow(2, k - 1, mod) % mod;
	
	return 0;
}