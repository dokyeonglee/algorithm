#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	long long x, b;
	cin >> x >> b;
	
	int sign = 1;
	
	if(b < 0){
		sign = -1;
		b = -b;
	}
	
	if(x == 0){
		cout << "0";
		return 0;
	}
	
	string answer = "";
	long long temp = (sign == 1 ? abs(x) : x);
	
	while(abs(temp) > 0){
		answer += to_string(((temp % b) + b) % b);
		temp -= ((temp % b) + b) % b;
		temp /= b;
		temp *= sign;
	}
	
	reverse(answer.begin(), answer.end());
	if(x < 0 and sign == 1){
		cout << "-";
	}
	cout << answer;
	
	return 0;
}