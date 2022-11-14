#define x1 first.first
#define x2 second.first
#define y1 first.second
#define y2 second.second

#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x > y){
		swap(x, y);
	}
	parent[y] = x;
}

bool intersect(pair<pii, pii>& a, pair<pii, pii>& b){
	return !(a.x2 < b.x1 or a.x1 > b.x2 or a.y2 < b.y1 or a.y1 > b.y2)
	and !(a.x1 < b.x1 and a.y1 < b.y1 and a.x2 > b.x2 and a.y2 > b.y2)
	and !(b.x1 < a.x1 and b.y1 < a.y1 and b.x2 > a.x2 and b.y2 > a.y2);
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	vector<pair<pii, pii>> rectangle(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> rectangle[i].x1 >> rectangle[i].y1 >> rectangle[i].x2 >> rectangle[i].y2;
		if(rectangle[i].first > rectangle[i].second){
			swap(rectangle[i].first, rectangle[i].second);
		}
		if(rectangle[i].y1 > rectangle[i].y2){
			swap(rectangle[i].y1, rectangle[i].y2);
		}
		for(int j = 0; j < i; j++){
			if(find_parent(parent, i) != find_parent(parent, j) and intersect(rectangle[i], rectangle[j])){
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
	
	cout << answer;
	
	return 0;
}