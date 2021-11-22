#include <iostream>
#include <vector>

#define x first
#define y second

using namespace std;

int is_inside(vector<pair<long long, long long>>& polygon, pair<long long, long long>& p){
	
	int cross_count = 0;
	
	for(int i = 0; i < polygon.size(); i++){
		if(polygon[i].first == p.x and polygon[i].second == p.y){
			return 1;
		}
		int j = (i + 1) % polygon.size();
		if((polygon[i].y > p.y) != (polygon[j].y > p.y)){
			double xx = (double)(polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x;
			if(p.x < xx){
				cross_count++;
			}
		}
	}
	
	return cross_count % 2;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<long long, long long>> polygon(n);
	for(int i = 0; i < n; i++){
		cin >> polygon[i].first >> polygon[i].second;
	}
	
	for(int i = 0; i < 3; i++){
		pair<long long, long long> p;
		cin >> p.first >> p.second;
		cout << is_inside(polygon, p) << "\n";
	}
	
	return 0;
}
