#include <iostream>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int answer = 1;
	while(n >= 5){
		answer = answer * 3 % 10007;
		n -= 3;
	}
	
	answer = answer * n % 10007;
	
	cout << answer;
	
	return 0;
}