#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	map<string, long long> cnt;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		if(str.size() > 2){
			sort(str.begin() + 1, str.end() - 1);
		}
		cnt[str]++;
	}
	
	int m;
	cin >> m;
	
	cin.ignore();
	
	for(int i = 0; i < m; i++){
		long long result = 1;
		string str;
		getline(cin, str);
		stringstream sstream(str);
		string word;
		while(getline(sstream, word, ' ')){
			if(word.size() > 2){
				sort(word.begin() + 1, word.end() - 1);
			}
			result *= cnt[word];
		}
		cout << result << "\n";
	}
	
	return 0;
}