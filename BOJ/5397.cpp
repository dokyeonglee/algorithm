#include <iostream>
#include <deque>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	deque<char> password;
	deque<char> temp;
	
	for(int test_case = 1; test_case <= t; test_case++){
		
		string log;
		cin >> log;
		
		for(char c : log){
			if(c == '-'){
				if(!password.empty()){
					password.pop_back();
				}
			}else if(c == '<'){
				if(!password.empty()){
					temp.push_front(password.back());
					password.pop_back();
				}
			}else if(c == '>'){
				if(!temp.empty()){
					password.push_back(temp.front());
					temp.pop_front();
				}
			}else{
				password.push_back(c);
			}
		}
		
		string answer = "";
		
		while(!password.empty()){
			answer += password.front();
			password.pop_front();
		}
		
		while(!temp.empty()){
			answer += temp.front();
			temp.pop_front();
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}