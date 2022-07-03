#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long w, h, f, c, x1, y1, x2, y2;
	cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
	
	if(w < 2 * f){
		f = w - f;
	}
	
	long long x = 0;
	if(x2 <= f){
		x = (x2 - x1) * 2;

	}else if(x1 <= f){
		x = (f - x1) * 2 + (x2 - f);
	}else{
		x = x2 - x1;
	}
	
	cout << w * h - x * (y2 - y1) * (c + 1);
	
	return 0;
}