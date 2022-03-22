#include <iostream>
#include <queue>
#include <set>

using namespace std;

string solve(set<string>& dictionary, string& word){
	
	set<string> visited;
	visited.insert(word);
	
	queue<string> q;
	q.push(word);
	
	string result = word;
	
	while(!q.empty()){
		string now = q.front();
		q.pop();
		for(int i = 0; i <= now.size(); i++){
			string next(now);
			next.insert(i, 1, 'a');
			for(int j = 'a'; j <= 'z'; j++){
				next[i] = j;
				if(!visited.count(next) and dictionary.count(next)){
					if(result.size() < next.size()){
						result = next;
					}
					visited.insert(next);
					q.push(next);
				}
			}
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	string word;
	cin >> word;
	
	set<string> dictionary;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		dictionary.insert(str);
	}
	
	cout << solve(dictionary, word);
	
	return 0;
}