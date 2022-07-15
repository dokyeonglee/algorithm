
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double x, y, c;
	cin >> x >> y >> c;
	
	double left = 0;
	double right = min(x, y);
	while(left < right){
		double mid = (left + right) / 2;
		double a = sqrt(x * x - mid * mid);
		double b = sqrt(y * y - mid * mid);
		double w = (a * b) / (a + b);
		if(abs(w - c) < 1e-3){
			cout << mid;
			return 0;
		}else if(w > c){
			left = mid;
		}else{
			right = mid;
		}
	}
	
	return 0;
}