#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	
	pair<double, double> src;
	double d, t;
	
	cin >> src.first >> src.second >> d >> t;
	
	double dist = sqrt(src.first * src.first + src.second * src.second);
	
	double answer = dist;
	int cnt = (int)(dist / d);
	
	answer = min(answer, cnt * t + dist - cnt * d);
	answer = min(answer, (cnt + 1) * t + (cnt + 1) * d - dist);
	
	if(cnt > 0){
		answer = min(answer, (cnt + 1) * t);
	}else{
		answer = min(answer, t * 2);
	}
	
	cout << fixed;
	cout.precision(10);
	cout << answer;
	
	return 0;
}