#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

double get_dist(vector<pair<double, double>>& pos, int x, int y){
	return sqrt((pos[x].first - pos[y].first) * (pos[x].first - pos[y].first)
		+ (pos[x].second - pos[y].second) * (pos[x].second - pos[y].second));
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<pair<double, double>> pos(n);
	for(int i = 0; i < n; i++){
		cin >> pos[i].first >> pos[i].second;
	}
	
	vector<pair<double, pair<int, int>>> edges;
	vector<int> parent(n + 1);
	
	for(int i = 0; i < n; i++){
		parent[i] = i;
		for(int j = i + 1; j < n; j++){
			double dist = get_dist(pos, i, j);
			edges.push_back(make_pair(dist, make_pair(i, j)));
		}
	}
	
	sort(edges.begin(), edges.end());
	
	double answer = 0;
	
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			answer += edges[i].first;
		}
	}
	
	cout << fixed;
	cout.precision(2);
	
	cout << answer;
	
	return 0;
}