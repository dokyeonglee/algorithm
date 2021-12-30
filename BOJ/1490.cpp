#include <iostream>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	long long temp = n;
	int lcm = 1;
	
	while(temp > 0){
		if(temp % 10 != 0){
			lcm = lcm * (temp % 10) / gcd(lcm, temp  % 10);
		}
		temp /= 10;
	}
	
	int ten = 1;
	while(1){
		for(int i = 0; i < ten; i++){
			if((n * ten + i) % lcm == 0){
				cout << n * ten + i;
				return 0;
			}
		}
		ten *= 10;
	}
	
	return 0;
}