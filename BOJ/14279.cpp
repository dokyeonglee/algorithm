#include <iostream>

using namespace std;

int main() {
	
	int a, b, c;
	cin >> a >> b >> c;
	
	int answer = 1e9;
	for(int i = 1; i <= c; i++){
		int x = c / i;
		int y = c / i + 1;
		answer = min(answer, abs(i - a) + abs(x - b) + abs(i * x - c));
		answer = min(answer, abs(i - a) + abs(y - b) + abs(i * y - c));
	}
		
	cout << answer;
	
	return 0;
}