#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return parent[x];
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& fee, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(fee[x] < fee[y]){
		parent[y] = x;
	}else{
		parent[x] = y;
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> parent(n + 1);
	vector<int> fee(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		cin >> fee[i];
	}
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		union_parent(parent, fee, x, y);
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		if(find_parent(parent, i) == i){
			answer += fee[i];		
		}
	}
	
	if(answer <= k){
		cout << answer;
	}else{
		cout << "Oh no";
	}
	
	return 0;
}