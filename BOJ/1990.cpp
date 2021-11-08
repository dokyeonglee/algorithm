#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

bool is_palindrome(int n){
	string str = to_string(n);
	string str2(str);
	reverse(str2.begin(), str2.end());
	return str == str2;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
		
	b = min(b, 10000000);	
	for(int i = a; i <= b; i++){
		if(is_palindrome(i) and is_prime(i)){
			cout << i << "\n";
		}
	}
	cout << "-1";
	
	return 0;
}