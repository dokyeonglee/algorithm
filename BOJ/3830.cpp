#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, vector<int>& weight, int x){
	if(parent[x] == x){
		return parent[x];
	}
	int p = find_parent(parent, weight, parent[x]);
	weight[x] += weight[parent[x]];
	return parent[x] = p;
}

void union_parent(vector<int>& parent, vector<int>& weight, int x, int y, int w){
	int x_parent = find_parent(parent, weight, x);
	int y_parent = find_parent(parent, weight, y);
	if(x_parent == y_parent){
		return;
	}
	parent[y_parent] = x_parent;
	weight[y_parent] = weight[x] + w - weight[y];
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
		
		vector<int> parent(n + 1);
		vector<int> weight(n + 1);
		
		for(int i = 1; i <= n; i++){
			parent[i] = i;
		}
		
		for(int i = 0; i < m; i++){
			char command;
			int a, b;
			cin >> command;
			if(command == '!'){
				int w;
				cin >> a >> b >> w;
				union_parent(parent, weight, a, b, w);
			}else{
				cin >> a >> b;
				if(find_parent(parent, weight, a) != find_parent(parent, weight, b)){
					cout << "UNKNOWN\n";
				}else{
					cout << weight[b] - weight[a] << "\n";
				}
			}
		}
	}
	
	return 0;
}