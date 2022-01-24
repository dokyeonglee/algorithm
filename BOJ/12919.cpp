#include <iostream>
#include <algorithm>

using namespace std;

void solve(string s, string t){
	if(s == t){
		cout << 1;
		exit(0);
	}
	if(s.size() >= t.size()){
		return;
	}
	
	if(t.back() == 'A'){
		string temp(t);
		temp.pop_back();
		solve(s, temp);
	}
	
	if(t.front() == 'B'){
		string temp(t);
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		solve(s, temp);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s, t;
	cin >> s >> t;
	
	solve(s, t);
	
	cout << 0;
	
	return 0;
}