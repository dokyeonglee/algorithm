#include <iostream>
#include <vector>
#include <algorithm>

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
	
	vector<pair<int, int>> robots(n);
	vector<pair<int, int>> shelters(n);
	
	for(int i = 0; i < n; i++){
		cin >> robots[i].first >> robots[i].second;
	}
	
	for(int i = 0; i < n; i++){
		cin >> shelters[i].first >> shelters[i].second;
	}
	
	vector<int> indices(n);
	for(int i = 0; i < n; i++){
		indices[i] = i;
	}
	
	do{
		bool check = true;
		vector<pair<pair<int, int>, pair<int, int>>> v(n);
		for(int i = 0; i < n; i++){
			v[i] = make_pair(robots[i], shelters[indices[i]]);
			if(v[i].first > v[i].second){
				swap(v[i].first, v[i].second);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(is_intersect(v[i], v[j])){
					check = false;
					break;
				}
			}
			if(!check){
				break;
			}
		}
		if(check){
			for(int i = 0; i < n; i++){
				cout << indices[i] + 1 << "\n";
			}
			return 0;
		}
	}while(next_permutation(indices.begin(), indices.end()));
	
	return 0;
}