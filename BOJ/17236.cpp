#include <iostream>
#include <cmath>

using namespace std;

double get_area(double a, double b, double c){
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int possible(double area, double ha, double hb, double hc){
	
	double a = 2 * area / ha;
	double b = 2 * area / hb;
	double c = 2 * area / hc;
	
	double _area = get_area(a, b, c);
	if(abs(area - _area) <= 1e-7){
		return 0;
	}else if(area > _area){
		return 1;
	}else{
		return 2;
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	double ha, hb, hc;
	cin >> ha >> hb >> hc;
	
	double answer = 0;
	double left = 0;
	double right = 1987654321;
	
	while(left < right){
		double mid = (left + right) / 2;
		int p = possible(mid, ha, hb, hc);
		if(p == 0){
			answer = mid;
			break;
		}else if(p == 1){
			left = mid;
		}else{
			right = mid;
		}
	}
	
	cout << fixed;
	cout.precision(6);
	cout << answer;
	
	return 0;
}