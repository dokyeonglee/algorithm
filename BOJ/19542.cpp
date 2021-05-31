#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& dist_to_leaf, int v, int p){
	
	int result = 0;
	
	for(int u : tree[v]){
		if(u != p){
			result = max(result, dfs(tree, dist_to_leaf, u, v) + 1);
		}
	}
	
	dist_to_leaf[v] = result;
	
	return dist_to_leaf[v];
}

int solve(vector<vector<int>>& tree, vector<int>& dist_to_leaf, int v, int p, int d){
	
	int result = 0;
	
	for(int u : tree[v]){
		if(u != p and dist_to_leaf[u] >= d){
			result += 2;
			result += solve(tree, dist_to_leaf, u, v, d);
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, s, d;
	cin >> n >> s >> d;
	
	vector<vector<int>> tree(n + 1);
	
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	vector<int> dist_to_leaf(n + 1);
	
	dfs(tree, dist_to_leaf, s, 0);
	cout << solve(tree, dist_to_leaf, s, 0, d) << "\n";
	
	return 0;
}