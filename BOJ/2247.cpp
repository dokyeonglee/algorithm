#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int answer = 0;
	for(int i = 2; i <= n; i++){
		answer += (n / i - 1) * i;
		answer %= 1000000;
	}
	
	cout << answer;
	
	return 0;
}