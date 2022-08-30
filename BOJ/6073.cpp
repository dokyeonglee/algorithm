#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Trie{
	int finish;
	Trie* next[2];
	int cnt;
	Trie() : finish(false), cnt(0){
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for(int i = 0; i < 2; i++){
			if(next[i]){
				delete next[i];
			}
		}
	}
	void insert(vector<int>& v, int idx){
		if(idx == v.size()){
			finish++;
		}else{
			cnt++;
			if(next[v[idx]] == NULL){
				next[v[idx]] = new Trie();
			}
			next[v[idx]]->insert(v, idx + 1);
		}
	}
	int count(vector<int>& v, int idx){
		if(idx == v.size()){
			return cnt + finish;
		}
		if(next[v[idx]] == NULL){
			return finish;
		}
		return finish + next[v[idx]]->count(v, idx + 1);
	}
};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Trie* trie = new Trie();
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vector<int> v(x);
		for(int j = 0; j < x; j++){
			cin >> v[j];
		}
		trie->insert(v, 0);
	}
	
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		vector<int> v(x);
		for(int j = 0; j < x; j++){
			cin >> v[j];
		}
		cout << trie->count(v, 0) << "\n";
	}

	return 0;
}