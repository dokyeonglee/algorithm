#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return parent[x];
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& water, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x < y){
		swap(x, y);
	}
	water[x] += water[y];
	parent[y] = x;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<int> parent(n + 1);
	vector<int> water(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> water[i];
		if(water[i] == 0){
			water[i] = -1;
		}
		parent[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, water, u, v);	
		}
	}
	
	for(int i = 0; i < q; i++){
		int x;
		cin >> x;
		if(water[find_parent(parent, x)] > 0){
			cout << "1\n";
		}else{
			cout << "0\n";
		}
	}
	
	return 0;
}