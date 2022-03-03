#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	long long arr[] = {0, 0, 153, 816, 0, 8568, 0, 31824, 0, 0, 0, 31824, 0, 8568, 0, 0, 0, 18};
	
	long long _a, _b;
	cin >> _a >> _b;
	
	double a = _a / 100.0;
	double b = _b / 100.0;
	
	double pa = 0;
	double pb = 0;
	for(int i = 2; i < 18; i++){
		if(arr[i]){
			pa += arr[i] * pow(a, i) * pow(1 - a, 18 - i);
			pb += arr[i] * pow(b, i) * pow(1 - b, 18 - i);
		}
	}
	
	cout << pa + pb - pa * pb;
	
	return 0;
}