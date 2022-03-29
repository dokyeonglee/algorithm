#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

long double f(long double a, long double b, long double c, long double x){
	return a * x + b * sinl(x) - c;
}

int main() {
	
	long double a, b, c;
	cin >> a >> b >> c;
	
	long double left = (c - b) / a;
	long double right = (c + b) / a;
	long double mid;
	
	cout << fixed;
	cout.precision(9);
			
	for(int i = 0; left < right and i < 50000; i++){
		mid = (left + right) / 2;
		if(f(a, b, c, mid) < 0){
			left = mid;
		}else{
			right = mid;
		}
	}
	
	cout << mid +  0.000000000000000005;
	
	return 0;
}