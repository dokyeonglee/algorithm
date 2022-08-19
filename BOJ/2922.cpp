#include <iostream>
#include <vector>

using namespace std;

long long dfs(string& str, int idx, int vowel, int consonant, bool l){
	if(vowel >= 3 or consonant >= 3){
		return 0;
	}
	if(idx == str.size()){
		return l;
	}
	long long ret = 0;
	char c = str[idx];
	if(c == '_'){
		ret += dfs(str, idx + 1, 0, consonant + 1, l) * 20;
		ret += dfs(str, idx + 1, 0, consonant + 1, true);
		ret += dfs(str, idx + 1, vowel + 1, 0, l) * 5;
	}else{
		if(c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'){
			ret += dfs(str, idx + 1, vowel + 1, 0, l);
		}else{
			ret += dfs(str, idx + 1, 0, consonant + 1, l | c == 'L');
		}
	}
	return ret;
}

int main() {
	
	string str;
	cin >> str;
	
	cout << dfs(str, 0, 0, 0, false);
	
	return 0;
}