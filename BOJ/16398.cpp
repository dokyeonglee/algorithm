#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(x == parent[x]){
		return parent[x];
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x < y){
		parent[y] = x;
	}else{
		parent[x] = y;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> parent(n);
	vector<vector<int>> planet_connection;
	
	for(int i = 0; i < n; i++){
		
		parent[i] = i;
		
		for(int j = 0; j < n; j++){
			int weight;
			cin >> weight;
			planet_connection.push_back({weight, i, j});
		}
	}
	
	sort(planet_connection.begin(), planet_connection.end());
	
	long long answer = 0;
	
	for(vector<int> e : planet_connection){
		int weight = e[0];
		int u = e[1];
		int v = e[2];
		if(find_parent(parent, u) != find_parent(parent, v)){
			answer += weight;
			union_parent(parent, u, v);
		}
	}
	
	cout << answer;
	
	return 0;
}