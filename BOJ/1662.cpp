#include <iostream>
#include <stack>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	stack<pair<int, int>> s;
	
	int length = 0;
	char temp;

	for(int i = 0; i < str.size(); i++){
		if(str[i] >= '0' and str[i] <= '9'){
			temp = str[i] - '0';
			length++;
		}else if(str[i] == '('){
			s.push(make_pair(temp, length - 1));
			length = 0;
		}else{
			length *= s.top().first;
			length += s.top().second;
			s.pop();
		}
	}	
	

	cout << length << endl;

	return 0;
}