#include <iostream>
#include <vector>
#include <tuple>
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
	
	int n;
	cin >> n;
	
	vector<tuple<int, int, int>> edges;
	vector<int> parent(n);
	
	int sum = 0;
	
	for(int i = 0; i < n; i++){
		
		parent[i] = i;
		
		string str;
		cin >> str;
		
		for(int j = 0; j < n; j++){
			
			int num = 0;
			
			if(str[j] >= 'a' and str[j] <= 'z'){
				num = str[j] - 'a' + 1;
			}else if(str[j] >= 'A' and str[j] <= 'Z'){
				num = str[j] - 'A' + 27;
			}
			
			sum += num;
			
			if(str[j] != '0'){
				if(i != j){
					edges.push_back(make_tuple(num, i, j));
				}
			}
			
		}
	}
	
	sort(edges.begin(), edges.end());
	
	int u, v, cost;
	int cnt = 1;
	
	for(auto edge : edges){
		
		tie(cost, u, v) = edge;
		
		if(find_parent(parent, u) != find_parent(parent, v)){
			sum -= cost;
			union_parent(parent, u, v);
			cnt++;		
		}
	}
	
	if(cnt < n){
		cout << -1;
	}else{
		cout << sum;
	}
	
	return 0;
}