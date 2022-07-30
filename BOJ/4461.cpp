#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		long long n;
		cin >> n;
		if(n == 0){
			break;
		}
		
		int sum = 987654321;
		
		for(long long c = 1; c <= 2000 and sum > 4000; c++){
			for(long long a = c; a + c <= 4000 and sum > 4000; a++){
				long long lo = 1;
				long long hi = 2000 - (a + 1) / 2 - (c + 1) / 2;
				while(lo <= hi){
					long long b = (lo + hi) / 2;
					long long left = a * a * a + c * c * c;
					long long right = b * b * b * n;
					if(left == right){
						if(sum > a + b + c + b){
							sum = a + b + c + b;
							cout << "(" << a << "/" << b << ")^3 + (" << c << "/" << b << ")^3 = " << n << "\n";
						}
						break;
					}else if(left < right){
						hi = b - 1;
					}else{
						lo = b + 1;
					}
				}
			}
		}
		
		if(sum > 4000){
			cout << "No value.\n";
		}
	}
	
	return 0;
}