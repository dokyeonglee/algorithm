#include <iostream>
#include <vector>
#include <algorithm>

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
	
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	vector<pair<int, pair<int, int>>> edges(m);
	for(int i = 0; i < m; i++){
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	}
	
	sort(edges.begin(), edges.end());
	
	int answer = 0;
	
	for(auto edge : edges){
		
		int c = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;
		
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			answer += c;
		}
	}
	
	cout << answer;
	
	return 0;
}