#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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
	
	int n;
	cin >> n;
	
	vector<int> parent(n + 1);
	vector<tuple<int, int, int>> edges;
	
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		for(int j = i + 1; j <= n; j++){
			int c;
			cin >> c;
			edges.push_back(make_tuple(c, i, j));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	int u, v, c;
	vector<vector<int>> answer(n + 1);
	
	for(auto edge : edges){
		tie(c, u, v) = edge;
		if(find_parent(parent, u) != find_parent(parent, v)){
			answer[u].push_back(v);
			answer[v].push_back(u);
			union_parent(parent, u, v);
		}
	}
	
	for(int i = 1; i <= n; i++){
		cout << answer[i].size() << " ";
		sort(answer[i].begin(), answer[i].end());
		for(int j = 0; j < answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}