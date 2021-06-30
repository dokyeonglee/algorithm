#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	
	while(s.size() < t.size()){
		char temp = t.back();
		t.pop_back();
		if(temp == 'B'){
			reverse(t.begin(), t.end());
		}
	}
	
	cout << (s == t);
	
	
	return 0;
}