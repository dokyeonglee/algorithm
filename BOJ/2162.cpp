#include <iostream>
#include <vector>

using namespace std;

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c){
	int cross_product = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
	if(cross_product > 0){
		return 1;
	}else if(cross_product < 0){
		return -1;
	}else{
		return 0;
	}
}

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	parent[y] = x;
	sz[x] += sz[y];
}

bool is_intersect(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b){
	int result = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
	int result2 = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
	if(result == 0 and result2 == 0){
		return b.first <= a.second and a.first <= b.second;
	}
	return result <= 0 and result2 <= 0;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> parent(n);
	vector<int> sz(n, 1);
	
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	vector<pair<pair<int, int>, pair<int, int>>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
		if(arr[i].first > arr[i].second){
			swap(arr[i].first, arr[i].second);
		}
		for(int j = 0; j < i; j++){
			if(find_parent(parent, i) != find_parent(parent, j)){
				if(is_intersect(arr[i], arr[j])){
					union_parent(parent, sz, i, j);	
				}
			}
		}
	}
	
	int cnt = 0;
	int max_size = 0;
	
	for(int i = 0; i < n; i++){
		if(find_parent(parent, i) == i){
			cnt++;
			max_size = max(max_size, sz[i]);
		}
	}
	
	cout << cnt << "\n" << max_size;
	
	return 0;
}