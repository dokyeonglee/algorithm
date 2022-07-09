#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int x, y;
	cin >> x >> y;
	
	int n = sqrt(abs(x - y));	
	
	if(n == 0){
		cout << 0;
	}else{
		cout << 2 * n - 1 + (n * n != abs(x - y)) + (n * n + n < abs(x - y));
	}
	
	return 0;
}