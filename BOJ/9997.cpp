#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void solve(vector<int>& word, int idx, int bit){
	if(idx == word.size()){
		answer += bit == (1 << 26) - 1;
		return;
	}
	solve(word, idx + 1, bit | word[idx]);
	solve(word, idx + 1, bit);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> word(n);
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			word[i] |= (1 << (str[j] - 'a'));
		}
	}
	
	solve(word, 0, 0);
	
	cout << answer;
	
	return 0;
}