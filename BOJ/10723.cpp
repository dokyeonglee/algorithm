#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

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

long long mst(vector<tuple<int, int, int>>& edges, int n){
	
	int u, v, c;
	
	sort(edges.begin(), edges.end());
	
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	long long result = 0;
	
	for(auto edge : edges){
		tie(c, u, v) = edge;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			result += c;
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n, m;
		cin >> n >> m;
		
		vector<tuple<int, int, int>> edges;
		int u, v, c;
		
		for(int i = 1; i <= n - 1; i ++){
			cin >> u >> c; 
			edges.push_back(make_tuple(c, i, u));
		}
		
		long long answer = 0;
		for(int i = 0; i < m; i++){
			cin >> u >> v >> c;
			edges.push_back(make_tuple(c, u, v));
			answer ^= mst(edges, n);
		}
		
		
		cout << answer << "\n";
	}
	
	return 0;
}