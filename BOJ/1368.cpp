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
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));
	
	for(int i = 1; i <= n; i++){
		cin >> graph[0][i];
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> graph[i][j];
		}
	}
	
	vector<pair<int, pair<int, int>>> edges;
	for(int i = 0; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			edges.push_back(make_pair(graph[i][j], make_pair(i, j)));
		}
	}
	
	vector<int> parent(n + 1);
	for(int i = 0; i <= n; i++){
		parent[i] = i;
	}
	
	sort(edges.begin(), edges.end());
	
	int answer = 0;
	for(auto edge : edges){
		auto [c, p] = edge;
		if(find_parent(parent, p.first) != find_parent(parent, p.second)){
			union_parent(parent, p.first, p.second);
			answer += c;
		}
	}
	
	cout << answer;
	
	return 0;
}