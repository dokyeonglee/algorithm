#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	string pattern;
	cin >> pattern;
	
	string answer(str);
	int idx = 0;
	int p_size = pattern.size();
	
	for(int i = 0; i < str.size(); i++){
		
		answer[idx++] = str[i];
		
		if(str[i] == pattern.back()){
			
			bool check = true;
			
			for(int j = idx - 1; j >= idx - p_size; j--){
				if(answer[j] != pattern[p_size - (idx - j)]){
					check = false;
					break;
				}
			}
			
			if(check){
				idx -= p_size;
			}
		}
		
	}
	
	if(idx == 0){
		cout << "FRULA";
	}else{
		for(int i = 0; i < idx; i++){
			cout << answer[i];
		}
	}
	
	return 0;
}