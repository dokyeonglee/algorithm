#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> phi;

long long euler_phi(long long n){
	
	if(phi.count(n)){
		return phi[n];
	}
	
	long long result = n;
	long long temp = n;
	
	for(long long i = 2; i * i <= n; i++){
		if(n % i == 0){
			result = result - result / i;
			while(n % i == 0){
				n /= i;
			}
		}
	}
	return phi[temp] = (n == 1 ? result : result - result / n);
}

long long mod(long long x, long long p){
	return x >= p ? x % p + p : x;
}

long long pow(long long a, long long n, long long m){

	int check = 0;

	if(n == 0){
		return 1;
	}
	long long result = pow(a, n / 2, m);
	if(result * result >= m){
		check = 1;
	}
	result = result * result % m;
	if(n % 2 == 1){
		if(result * a >= m){
			check = 1;
		}
		result = result * a % m;
	}
	return result + m * check;
}

long long solve(vector<long long>& arr, int idx, long long m){
	if(idx == arr.size() - 1 or m == 1){
		return mod(arr.back(), m);
	}
	return pow(arr[idx], solve(arr, idx + 1, euler_phi(m)), m);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long T, M;
	cin >> T >> M;
	
	while(T--){
		int n;
		cin >> n;
		vector<long long> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		cout << solve(arr, 0, M) % M << "\n";
	}
	
	return 0;
}