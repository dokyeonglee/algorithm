#include <iostream>
#include <vector>

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
	
	vector<int> parent(n + m + 1);
	for(int i = 1; i <= n + m; i++){
		parent[i] = i;
	}
	
	int cant_lie_num;
	cin >> cant_lie_num;
	
	int num, x;
	
	for(int i = 0; i < cant_lie_num; i++){
		cin >> num;
		union_parent(parent, 0, num);
	}
	
	int answer = m;
	
	for(int i = 1; i <= m; i++){
		cin >> num;
		for(int j = 0; j < num; j++){
			cin >> x;
			if(find_parent(parent, n + i) != find_parent(parent, x)){
				union_parent(parent, n + i, x);
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		if(find_parent(parent, 0) == find_parent(parent, n + i)){
			answer--;
		}
	}
	
	cout << answer;
	
	return 0;
}