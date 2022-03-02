#include <iostream>
#include <vector>

using namespace std;

__int128 pow(__int128 a, __int128 n, __int128 mod){
	if(n == 1){
		return a;
	}
	__int128 result = pow(a, n / 2 , mod);
	result = result * result % mod;
	if(n % 2 == 1){
		result = result * a % mod;
	}
	return result;
}

__int128 sum_a0_to_an(__int128 a, __int128 n, __int128 m){
	if(n == 0){
		return 1;
	}
	if(n == 1){
		return (a + 1) % m;
	}
	__int128 result = sum_a0_to_an(a, n / 2, m);
	__int128 temp = pow(a, n / 2, m);
	result = (result * temp + result - temp) % m;
	result = (result + m) % m;
	if(n % 2 == 1){
		result = (pow(a, n , m) + result) % m;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long m, a, c, x, n, g;
	cin >> m >> a >> c >> x >> n >> g;
	
	__int128 answer;
	if(a == 0){
		answer = c % g;
	}else if(a == 1){
		answer = (x + (__int128)n * c) % g;
	}else{
		answer = pow(a, n, m) * x % m;
		answer = (answer + sum_a0_to_an(a, n - 1, m) * c % m) % m;
		answer %= g;
	}
	
	cout << (long long)answer;
	
	return 0;
}