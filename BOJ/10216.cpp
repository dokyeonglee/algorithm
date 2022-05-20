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

bool is_connectable(pair<int, int> a, pair<int, int> b, int r1, int r2){
	int dist_square = (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
	return dist_square <= (r1 + r2) * (r1 + r2);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> parent(n + 1);
		for(int i = 1; i <= n; i++){
			parent[i] = i;
		}
		
		vector<pair<int, int>> arr(n + 1);
		vector<int> r(n + 1);
		
		for(int i = 1; i <= n; i++){
			cin >> arr[i].first >> arr[i].second >> r[i];
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(is_connectable(arr[i], arr[j], r[i], r[j])){
					union_parent(parent, i, j);	
				}
			}
		}
		
		int answer = 0;
		
		for(int i = 1; i <= n; i++){
			if(find_parent(parent, i) == i){
				answer++;
			}
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}