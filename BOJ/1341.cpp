#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	long long a, b;
	cin >> a >> b;
	
	if(a == 0){
		cout << "-";
		return 0;
	}
	
	if(a == b){
		cout << "*";
		return 0;
	}
	
	if((b & (b - 1)) == 0){
		cout << -1;
		return 0;
	}
	
	int n = -1;
	for(int i = 1; i < 61; i++){
		if(((1ll << i) - 1) % b == 0){
			n = i;
			a *= ((1ll << i) - 1) / b;
			break;
		}
	}
	
	if(n == -1){
		cout << -1;
		return 0;
	}
	
	string answer = "";
	for(int i = n - 1; i >= 0; i--){
		answer += (a & (1ll << i)) > 0 ? '*' : '-';
	}
	cout << answer;
	
	return 0;
}