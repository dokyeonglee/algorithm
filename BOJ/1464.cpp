#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	string str;
	cin >> str;
	
	string answer = str.substr(0, 1);
	for(int i = 1; i < str.size(); i++){
		if(answer[i - 1] < str[i]){
			answer = str[i] + answer;
		}else{
			answer += str[i];
		}
	}
	
	reverse(answer.begin(), answer.end());
	cout << answer;
	
	return 0;
}