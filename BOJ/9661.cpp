#include <iostream>
using namespace std;

int main() {
	
	long long n;
	cin >> n;
	
	n %= 5;
	
	if(n == 1 or n == 3 or n == 4){
		cout << "SK";	
	}else{
		cout << "CY";
	}
	
	return 0;
}