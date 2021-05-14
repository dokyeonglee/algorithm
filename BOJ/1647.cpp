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

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	vector<tuple<int, int, int>> edges;
	
	int u, v, c;
	
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;
		edges.push_back(make_tuple(c, u, v));
	}
	
	sort(edges.begin(), edges.end());
	
	int answer = 0;
	int cnt = 1;
	
	for(auto edge : edges){
		tie(c, u, v) = edge;
		if(cnt < n - 1 and find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			answer += c;
			cnt++;
		}
	}
	
	cout << answer;
	
	return 0;
}