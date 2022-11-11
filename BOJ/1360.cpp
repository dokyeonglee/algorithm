#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, string>> v;
	string now = "";
	
	v.push_back(make_pair(-1e9, now));
	
	while(n--){
		string command;
		cin >> command;
		if(command == "type"){
			
			char c;
			int t;
			cin >> c >> t;
			
			now += c;
			v.push_back(make_pair(t, now));
			
		}else{
			
			int t, tt;
			cin >> t >> tt;
			
			for(int i = v.size() - 1; i >= 0; i--){
				if(v[i].first < tt - t){
					now = v[i].second;
					v.push_back(make_pair(tt, now));
					break;
				}
			}
			
		}
	}
	
	cout << v.back().second;
	
	return 0;
}