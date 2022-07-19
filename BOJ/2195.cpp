#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	
	map<char, vector<int>> indices;
	
	for(int i = 0; i < a.size(); i++){
		indices[a[i]].push_back(i);
	}
	
	int idx = 0;
	int answer = 0;
	
	while(idx < b.size()){
		int match = 0;
		for(int i : indices[b[idx]]){
			int cnt = 0;
			int j = idx;
			while(i < a.size() and j < b.size() and a[i] == b[j]){
				cnt++;
				i++;
				j++;
			}
			match = max(match, cnt);
		}
		idx += match;
		answer++;
	}
	
	cout << answer;
	
	return 0;
}