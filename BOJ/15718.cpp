#include <iostream>
#include <vector>

using namespace std;

long long lucas(vector<vector<long long>>& C, int n, int m, int mod){
	long long result = 1;
	while(n != 0 and m != 0){
		result = result * C[n % mod][m % mod] % mod;
		n /= mod;
		m /= mod;
	}
	return result;
}

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
	
	int T;
	cin >> T;
	
	vector<vector<long long>> C(1032, vector<long long>(1032));
	vector<vector<long long>> C2(C);
	
	for(int i = 0; i <= 1031; i++){
		C[i][0] = 1;
		C2[i][0] = 1;
		for(int j = 1; j <= i; j++){
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 97;
			C2[i][j] = (C2[i - 1][j] + C2[i - 1][j - 1]) % 1031;
		}
	}
	
	long long inv97 = pow(97, 1029, 1031);
	long long inv1031 = pow(1031, 95, 97);
	
	long long inv7 = pow(7, 3, 5);
	long long inv5 = pow(5, 5, 7);
	
	while(T--){
		int n, m;
		cin >> n >> m;
		if(n == 0 and m == 1){
			cout << 1 << "\n";
			continue;
		}
		if(n == 0 or m == 1){
			cout << 0 << "\n";
			continue;
		}
		
		if(n - 1 < m - 2){
			cout << 0 << "\n";
			continue;
		}
		
		long long r1 = lucas(C, n - 1, m - 2, 97);
		long long r2 = lucas(C2, n - 1, m - 2, 1031);
		long long a1 = 1031 * inv1031 * r1;
		long long a2 = 97 * inv97 * r2;
		cout << (a1 + a2) % 100007 << "\n";
	}
	
	return 0;
}