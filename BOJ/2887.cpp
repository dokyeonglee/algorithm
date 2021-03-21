#include <iostream>
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

bool compare_x(vector<int>& a, vector<int>& b){
	return a[0] < b[0];
}

bool compare_y(vector<int>& a, vector<int>& b){
	return a[1] < b[1];
}

bool compare_z(vector<int>& a, vector<int>& b){
	return a[2] < b[2];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> planet(n, vector<int>(4));
	vector<int> parent(n);
	
	for(int i = 0; i < n; i++){
		cin >> planet[i][0] >> planet[i][1] >> planet[i][2];
		planet[i][3] = i;
		parent[i] = i;
	}
	
	vector<vector<int>> edges;
	bool (*compare[])(vector<int>&, vector<int>&) = {compare_x, compare_y, compare_z};
	
	for(int i = 0; i < 3; i++){
		sort(planet.begin(), planet.end(), compare[i]);
		for(int j = 1; j < n; j++){
			edges.push_back({abs(planet[j - 1][i] - planet[j][i]), planet[j - 1][3], planet[j][3]});	
		}
	}
	
	sort(edges.begin(), edges.end());
	
	long long answer = 0;
	
	for(vector<int> edge : edges){
		
		int u = edge[1];
		int v = edge[2];
		
		if(find_parent(parent, u) != find_parent(parent, v)){
			answer += edge[0];
			union_parent(parent, u, v);
		}
	}
	
	cout << answer;
	
	return 0;
}