#include <iostream>
#include <vector>

using namespace std;

int string_to_bit(string str){
	int result = 0;
	for(int i = 0; i < str.size(); i++){
		result |= 1 << (str[i] - 'a');
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> bit_words(n);
	for(int i = 0; i < n; i++){
		string word;
		cin >> word;
		bit_words[i] = string_to_bit(word);
	}
	
	int remember = 0x3ffffff;
	for(int i = 0; i < m; i++){
		
		int answer = 0;
		int o;
		char x;
		cin >> o >> x;
		
		if(o == 1){
			remember &= ~(1 << (x - 'a'));
		}else{
			remember |= 1 << (x - 'a');
		}
		
		for(int j = 0; j < n; j++){
			if((bit_words[j] & remember) == bit_words[j]){
				answer++;
			}
		}
		
		cout << answer << '\n';
	}
	
	return 0;
}