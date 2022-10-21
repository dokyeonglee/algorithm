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

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	parent[y] = x;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}

	for(int i = 0; i < n - 2; i++){
		int u, v;
		cin >> u >> v;
		union_parent(parent, u, v);
	}
	
	set<int> answer;
	for(int i = 1; i <= n; i++){
		answer.insert(find_parent(parent, i));
	}
	
	for(auto it : answer){
		cout << it << " ";
	}
	
	return 0;
}