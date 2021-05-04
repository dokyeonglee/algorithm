#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long mem[2001][2001];

long long comb(long long n, long long r, long long m){
	
	if(n < r){
		return 0;
	}
	
	if(r == 0 or n == r){
		return 1;
	}
	
	long long& result = mem[n][r];
	
	if(result != -1){
		return result;
	}
	
	result = (comb(n - 1, r - 1, m) % m + comb(n - 1, r, m) % m) % m;
	
	return result;	
}

int main() {

	memset(mem, -1, sizeof(mem));

	long long n, r, m;
	cin >> n >> r >> m;
	
	long long answer = 1;
	
	while(n > 0 or r > 0){
		answer = answer * comb(n % m, r % m, m) % m;
		n /= m;
		r /= m;
	}
	
	cout << answer;
	
	return 0;
}