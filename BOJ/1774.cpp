#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
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
	
	vector<pair<int, int>> pos(n + 1);
	vector<int> parent(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> pos[i].first >> pos[i].second;
		parent[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);	
		}
	}
	
	vector<tuple<long long, int, int>> edges;
	
	double answer = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j){
				long long cost = (long long)(pos[i].first - pos[j].first) * (pos[i].first - pos[j].first) + (long long)(pos[i].second - pos[j].second) * (pos[i].second - pos[j].second);
				edges.push_back(make_tuple(cost, i, j));
			}
		}
	}
	
	sort(edges.begin(), edges.end());
	
	int u, v, c;
	
	for(auto edge : edges){
		
		tie(c, u, v) = edge;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			answer += sqrt(c);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << answer;
	
	return 0;
}