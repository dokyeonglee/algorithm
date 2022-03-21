#include <iostream>
#include <vector>

using namespace std;

void init(vector<vector<int>>& tree, vector<int>& parent, vector<int>& depth, int now, int p, int d){
	depth[now] = d;
	parent[now] = p;
	for(int next : tree[now]){
		if(next != p){
			init(tree, parent, depth, next, now, d + 1);
		}
	}
}

int lca(vector<vector<int>>& tree, vector<int>& parent, vector<int>& depth, int u, int v){
	int u_depth = depth[u];
	int v_depth = depth[v];
	while(u_depth > v_depth){
		u = parent[u];
		u_depth--;
	}
	while(u_depth < v_depth){
		v = parent[v];
		v_depth--;
	}
	while(u != v){
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> tree(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	
	vector<int> parent(n + 1);
	vector<int> depth(n + 1);
	
	init(tree, parent, depth, 1, 0, 1);
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		cout << lca(tree, parent, depth, u, v) << "\n";
	}
	
	return 0;
}