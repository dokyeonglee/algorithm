#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<int> s;
	s.push(2e9);
	
	long long answer = 0;
	int _max = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(s.top() != x){
			answer += max(x - s.top(), 0);
			s.pop();
			s.push(x);
		}
		_max = max(_max, x);
	}
	
	while(!s.empty()){
		answer += _max - s.top();
		s.pop();
	}
	
	cout << answer;
	
	return 0;
}