#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

using pdd = pair<double, double>;

pdd operator +(const pdd& p1, const pdd& p2){
	return make_pair(p1.first + p2.first, p1.second + p2.second);
}

pdd operator -(const pdd& p1, const pdd& p2){
	return make_pair(p1.first - p2.first, p1.second - p2.second);
}

pdd operator *(const pdd& p1, const pdd& p2){
	return make_pair(p1.first * p2.first - p1.second * p2.second, p1.first * p2.second + p1.second * p2.first);
}

double get_distance(pdd a){
	return sqrt(a.first * a.first + a.second * a.second);
}

pdd sqrt(pdd a){
	double distance = sqrt(get_distance(a));
	double theta = atan2(a.second, a.first) / 2;
	return make_pair(distance * cos(theta), distance * sin(theta));
}

double round2(double a){
	return round(a * 100) / 100;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	cout << fixed;
	cout.precision(2);
		
	while(t--){
		pair<double, double> a, b, c;
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
		
		pdd abc_sum = a + b + c;
		pdd offset = sqrt(a * a + b * b + c * c - a * b - b * c - a * c);
		pdd m = a + b;
		
		m.first /= 2;
		m.second /= 2;
		
		pdd f1 = abc_sum + offset;	
		pdd f2 = abc_sum - offset;
		if(f1 > f2){
			swap(f1, f2);
		}
		
		f1.first /= 3;
		f1.second /= 3;
		f2.first /= 3;
		f2.second /= 3;
		
		cout << round2(f1.first) << " " << round2(f1.second) << " ";
		cout << round2(f2.first) << " " << round2(f2.second) << " ";
		cout << round2(get_distance(m - f1) + get_distance(m - f2)) << "\n";
		
	}
	
	
	return 0;
}