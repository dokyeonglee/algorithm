#include <iostream>
#include <vector>

using namespace std;

vector<int> failure_function(string& s){
	
	vector<int> partial_match(s.size());
	
	int begin = 1;
	int matched = 0;
	
	while(begin + matched < s.size()){
		if(s[begin + matched] == s[matched]){
			partial_match[begin + matched - 1] = ++matched;
		}else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - partial_match[matched - 1];
				matched = partial_match[matched - 1];
			}
		}
	}
	
	return partial_match;
}

vector<int> kmp(string& hay, string& needle){
	
	int n = hay.size();
	int m = needle.size();
	
	vector<int> result;
	vector<int> partial_match = failure_function(needle);
	
	int begin = 0;
	int matched = 0;
	
	while(begin <= n - m){
		if(matched < m and hay[begin + matched] == needle[matched]){
			if(++matched == m){
				result.push_back(begin);
			}
		}else{
			if(matched == 0){
				begin++;
			}else{
				begin += matched - partial_match[matched - 1];
				matched = partial_match[matched - 1];
			}
		}
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string T, P;
	getline(cin, T);
	getline(cin, P);
	
	vector<int> answer = kmp(T, P);
	
	cout << answer.size() << '\n';
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] + 1 << " ";
	}
	
	cout << '\n';
	
	return 0;
}