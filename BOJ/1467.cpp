#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	string str2;
	cin >> str2;
	
	vector<int> cnt(10);
	for(int i = 0; i < str.size(); i++){
		cnt[str[i] - '0']++;
	}
	vector<int> cnt2(10);
	for(int i = 0; i < str2.size(); i++){
		cnt2[str2[i] - '0']++;
	}
	
	string answer = "";
	for(int i = 0; i < str.size(); i++){
		if(cnt[str[i] - '0'] <= cnt2[str[i] - '0']){
			continue;
		}
		auto temp = cnt2;
		int j;
		for(j = i; j < str.size(); j++){
			if(str[j] > str[i] and cnt[str[j] - '0'] != cnt2[str[j] - '0']){
				break;
			}
			if(temp[str[j] - '0'] > 0){
				temp[str[j] - '0']--;
			}else{
				j = str.size();
				break;
			}
		}
		if(j == str.size()){
			answer += str[i];
		}else{
			cnt2[str[i] - '0']--;
		}
		cnt[str[i] - '0']--;
	}
	
	cout << answer;
	
	return 0;
}