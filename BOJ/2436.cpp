#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int g, l;
	cin >> g >> l;
	
	int ab = l / g;
	int a = -1;
	int b = -1;
	
	for(int i = 1; i * i <= ab; i++){
		if(ab % i == 0){
			if(gcd(i, ab / i) == 1){
				a = i * g;
				b = ab / i * g;
			}
		}
	}
	
	cout << a << " " << b;
	
	return 0;
}