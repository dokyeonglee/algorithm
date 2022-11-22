#include <iostream>
using namespace std;


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	if(str == "0"){
		cout << "W";
		return 0;
	}
	
	int x = 0;
	int c = 0;
	int idx = 0;
	int sign = 1;
		
	while(idx < str.size()){
		long long temp = 0;
		int temp_idx = idx;
		while(str[idx] >= '0' and str[idx] <= '9'){
			temp = temp * 10 + (str[idx] - '0');
			idx++;
		}
		if(str[idx] == 'x'){
			if(temp_idx == idx){
				temp = 1;
			}
			x = sign * temp;
		}else{
			c = sign * temp;
			if(str[idx] == '+'){
				sign = 1;
			}else if(str[idx] == '-'){
				sign = -1;
			}
		}
		idx++;
	}
	
	if(abs(x) > 0){
		if(x / 2 == -1){
			cout << "-";
		}
		if(abs(x / 2) != 1){
			cout << x / 2;
		}
		cout << "xx";
	}
	
	if(abs(c) > 0){
		if(c > 0 and abs(x) > 0){
			cout << "+";
		}
		if(c == -1){
			cout << "-";
		}
		if(abs(c) != 1){
			cout << c;
		}
		cout << "x";
	}
	
	cout << "+W";
	
	return 0;
}