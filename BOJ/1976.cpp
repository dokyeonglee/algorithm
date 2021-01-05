#include <iostream>
#include <vector>

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
	if(x < y){
		parent[y] = x;
	}else{
		parent[x] = y;
	}
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
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			
			int is_connect;
			cin >> is_connect;
			
			if(is_connect == 1){
				union_parent(parent, i, j);
			}
		}
	}

	bool possible = true;
	vector<int> city(m);
	cin >> city[0];
	city[0] = find_parent(parent, city[0]);

	for(int i = 1; i < m; i++){
		cin >> city[i];
		if(city[0] != find_parent(parent, city[i])){
			possible = false;
			break;
		}
	}
	
	if(possible){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	
	return 0;
}