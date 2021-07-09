#include <iostream>
#include <vector>

using namespace std;

int distance(pair<int, int>& a, pair<int, int>& b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> pos(n);
	for(int i = 0; i < n; i++){
		cin >> pos[i].first >> pos[i].second;
	}
	
	int min_dist = 987654321;
	int min_idx = 0;
	
	for(int i = 0; i < n; i++){
		
		int max_dist = 0;
		
		for(int j = 0; j < n; j++){
			
			int dist = distance(pos[i], pos[j]);
			
			if(max_dist < dist){
				max_dist = dist;
			}
		}
		
		if(min_dist > max_dist){
			min_dist = max_dist;
			min_idx = i;
		}
	}
	
	cout << pos[min_idx].first << " " << pos[min_idx].second;
	
	return 0;
}