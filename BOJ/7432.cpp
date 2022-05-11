#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Trie{
	public:
		map<string, Trie*> next;
		void insert(string str){
			Trie* curr = this;
			stringstream ss(str);
			string s;
			while(getline(ss, s, '\\')){
				if(curr->next[s] == nullptr){
					curr->next[s] = new Trie;
				}
				curr = curr->next[s];
			}
		}
		void print(int depth){
			vector<string> v;
			for(auto it : next){
				v.push_back(it.first);
			}
			sort(v.begin(), v.end());
			for(int i = 0; i < v.size(); i++){
				for(int j = 0; j < depth; j++){
					cout << " ";
				}
				cout << v[i] << "\n";
				next[v[i]]->print(depth + 1);
			}
		}
};

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Trie trie;
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		trie.insert(str);
	}
	
	trie.print(0);
	
	return 0;
}