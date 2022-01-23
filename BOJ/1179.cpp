#include <iostream>

using namespace std;

long long joseph(long long n, long long k){
	if(n == 1){
		return 0;
	}
	if(k == 1){
		return n - 1;
	}
	if(k > n){
		return (joseph(n - 1, k) + k) % n;
	}
	long long cnt = n / k;
	long long result = joseph(n - cnt, k);
	result -= n % k;
	if(result < 0){
		result += n;
	}else{
		result += result / (k - 1);
	}
	return result;
}

int main() {
	
	long long n, k;
	cin >> n >> k;
	
	cout << joseph(n, k) + 1;
	
	return 0;
}