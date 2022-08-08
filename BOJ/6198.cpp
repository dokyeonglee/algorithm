#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	long long answer = 0;
	
	stack<int> s;
	for(int i = 0; i < n; i++){
		int h;
		cin >> h;
		while(!s.empty() and s.top() <= h){
			s.pop();	
		}
		answer += s.size();
		s.push(h);
	}
	
	cout << answer;
	
	return 0;
}