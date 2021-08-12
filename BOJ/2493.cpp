#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<pair<int, int>> s;
	s.push(make_pair(0, 987654321));
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		while(s.top().second < x){
			s.pop();
		}
		cout << s.top().first << " ";
		s.push(make_pair(i + 1, x));
	}
	
	return 0;
}