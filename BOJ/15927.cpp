#include <iostream>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	int answer = -1;
	bool check = false;
	
	for(int i = 0; i < str.size() / 2; i++){
		if(str[i] != str[str.size() - 1 - i]){
			cout << str.size();
			return 0;
		}else if(str[i] != str[i + 1]){
			check = true;
		}
	}
	
	if(check){
		cout << str.size() - 1;
	}else{
		cout << -1;
	}
	
	
	return 0;
}