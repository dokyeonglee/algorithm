#include <iostream>
using namespace std;

int fac_unit_digit[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};

string div_five(string num){
	string result = "";
	
	int dividend = 0;
	for(int i = 0; i < num.size(); i++){
		dividend = dividend * 10 + num[i] - '0';
		result += dividend / 5 + '0';
		dividend %= 5;
	}
	
	if(result[0] == '0'){
		result = result.substr(1);
	}
	
	return result;
}

int solve(string& num){
	
	int unit_digit = num.back() - '0';
	
	if(num.size() == 1){
		return fac_unit_digit[unit_digit];
	}
	
	int second_last_digit = num[num.size() - 2] - '0';
	string quotient = div_five(num);
	
	return (6 - second_last_digit % 2 * 2) * solve(quotient) * fac_unit_digit[unit_digit] % 10;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string n;
	cin >> n;
	
	cout << solve(n);
	
	return 0;
}