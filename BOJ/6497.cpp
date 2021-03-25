#include <iostream>
#include <tuple>
#include <vector>
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

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n, m;
		cin >> n >> m;
		
		if(n == 0 and m == 0){
			break;
		}
		
		vector<int> parent(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
		
		int u, v, c;
		int answer = 0;
		
		vector<tuple<int, int, int>> edges(m);
		for(int i = 0; i < m; i++){
			cin >> 	u >> v >> c;
			answer += c;
			edges[i] = make_tuple(c, u, v);
		}
		
		sort(edges.begin(), edges.end());
		
		for(auto edge : edges){
			tie(c, u, v) = edge;
			if(find_parent(parent, u) != find_parent(parent, v)){
				union_parent(parent, u, v);
				answer -= c;
			}
		}
		
		cout << answer << '\n';	
	}
	
	
	return 0;
}