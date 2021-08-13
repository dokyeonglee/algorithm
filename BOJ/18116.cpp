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

void union_parent(vector<int>& parent, vector<long long>& cnt, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	cnt[y] += cnt[x];
	cnt[x] = 0;
	parent[x] = y;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> parent(1000001);
	vector<long long> cnt(1000001, 1);
	
	for(int i = 1; i <= 1000000; i++){
		parent[i] = i;
	}
	
	while(n--){
		char c;
		cin >> c;
		if(c == 'I'){
			int u, v;
			cin >> u >> v;
			if(find_parent(parent, u) != find_parent(parent, v)){
				union_parent(parent, cnt, u, v);	
			}
		}else{
			int u;
			cin >> u;
			cout << cnt[find_parent(parent, u)] << "\n";
		}
	}
	
	return 0;
}