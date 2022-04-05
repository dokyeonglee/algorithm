#include <iostream>

using namespace std;

int main() {
	
	long long g;
	cin >> g;
	
	long long x = 1;
	long long y = 1;
	bool check = false;
	
	while(x < g){
		if(x * x - y * y > g){
			y++;
		}else if(x * x - y * y == g){
			check = true;
			cout << x << "\n";
			x++;
		}else{
			x++;
		}
	}
	
	if(!check){
		cout << -1;
	}
	
	return 0;
}