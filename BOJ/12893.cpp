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
	
	vector<int> parent(n + 1);
	vector<int> enemy(n + 1);
	
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		
		int u, v;
		cin >> u >> v;
		
		if(find_parent(parent, u) == find_parent(parent, v)){
			cout << "0";
			return 0;
		}
		
		if(enemy[u]){
			union_parent(parent, v, enemy[u]);
		}else{
			enemy[u] = v;
		}
		
		if(enemy[v]){
			union_parent(parent, u, enemy[v]);
		}else{
			enemy[v] = u;
		}
		
	}
	
	cout << 1;
	
	return 0;
}