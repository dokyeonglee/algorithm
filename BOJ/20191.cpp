#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string S, T;
	cin >> S >> T;
	
	map<char, vector<int>> idx;
	
	for(int i = 0; i < T.size(); i++){
		idx[T[i]].push_back(i);	
	}
	
	for(int i = 0; i < S.size(); i++){
		if(idx[S[i]].empty()){
			cout << -1;
			return 0;
		}
	}
	
	int cnt = 1;
	int pos = -1;
	
	for(int i = 0; i < S.size(); i++){
		auto it = lower_bound(idx[S[i]].begin(), idx[S[i]].end(), pos + 1);
		if(it == idx[S[i]].end()){
			cnt++;
			it = idx[S[i]].begin();
		}
		pos = *it;
	}
	
	cout << cnt;
	
	return 0;
}