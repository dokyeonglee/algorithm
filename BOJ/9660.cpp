#include <iostream>

using namespace std;


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	if(n % 7 == 0 or n % 7 == 2){
		cout << "CY";
	}else{
		cout << "SK";
	}
	
	return 0;
}