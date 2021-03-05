#include <iostream>

using namespace std;

bool is_prime(int n){
	
	if(n < 2){
		return false;
	}
	
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	
	return true;
}

void solve(int num, int digit){
	if(digit == 0){
		cout << num << '\n';
		return;
	}
	for(int i = 0; i < 10; i++){
		int temp = num * 10 + i;
		if(is_prime(temp)){
			solve(temp, digit - 1);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	solve(0, n);
	
	return 0;
}