#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	vector<int> cnt(26);
	vector<int> picked(n, false);
	vector<vector<int>> ch_index(26);
	for(int i = 0; i < str.size(); i++){
		cnt[str[i] - 'a']++;
		ch_index[str[i] - 'a'].push_back(i);
	}
	
	string a = "";
	string b = "";
	
	int pos = n - 1;
	
	while(pos >= 0){
		while(picked[pos]){
			pos--;
		}
		if(pos < 0){
			break;
		}
		a += str[pos];
		cnt[str[pos] - 'a']--;
		picked[pos] = true;
		ch_index[str[pos] - 'a'].pop_back();
		
		char ch;
		for(int i = 0; i < 26; i++){
			if(cnt[i] > 0){
				ch = 'a' + i;
				cnt[i]--;
				break;
			}
		}
		b += ch;
		int idx = ch_index[ch - 'a'].back();
		ch_index[ch - 'a'].pop_back();
		picked[idx] = true;
	}
	
	if(a <= b){
		cout << "NE\n";
	}else{
		cout << "DA\n";
	}
	
	cout << b;
	
	return 0;
}