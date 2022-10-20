#include <iostream>
#include <vector>
#include <set>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<set<int>>& s, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(s[x].size() < s[y].size()){
		swap(x, y);
	}
	for(int c : s[y]){
		s[x].insert(c);
	}
	parent[y] = x;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> p(n + 1);
	for(int i = 2; i <= n; i++){
		cin >> p[i];
	}
	
	vector<int> color(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> color[i];
	}
	
	vector<int> parent(n + 1);
	vector<set<int>> s(n + 1);
	
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		s[i].insert(color[i]);
	}
	
	vector<pair<int, int>> queries(n + q - 1);
	for(int i = 0; i < queries.size(); i++){
		cin >> queries[i].first >> queries[i].second;
	}
	
	vector<int> answer;
	for(int i = queries.size() - 1; i >= 0; i--){
		auto [command, a] = queries[i];
		if(command == 1){
			union_parent(parent, s, a, p[a]);
		}else{
			answer.push_back(s[find_parent(parent, a)].size());
		}
	}
	
	for(int i = answer.size() - 1; i >= 0; i--){
		cout << answer[i] << "\n";
	}
	
	return 0;
}