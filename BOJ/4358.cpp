#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	map<string, double> m;
	
	string str;
	int cnt = 0;
	
	while(getline(cin, str)){
		cnt++;
		m[str] += 1;
	}
	
	cout << fixed;
	cout.precision(4);
	for(auto it = m.begin(); it != m.end(); it++){
		cout << it->first << " " << it->second / cnt * 100 << "\n";
	}
	
	return 0;
}