#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return parent[x];
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
	
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n);
	
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		if(find_parent(parent, x) == find_parent(parent, y)){
			cout << i + 1;
			return 0;
		}
		union_parent(parent, x, y);
	}
	
	cout << 0;
	
	return 0;
}