#include <iostream>
#include <vector>

using namespace std;
using pii_pii = pair<pair<int, int>, pair<int, int>>;

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
		if(a.first > a.second){
			swap(a.first, a.second);
		}
		if(b.first > b.second){
			swap(b.first, b.second);
		}
		return b.first <= a.second and a.first <= b.second;
	}
	return result <= 0 and result2 <= 0;
}

bool check(pair<int, int>& a, pair<int, int>& b, pair<int, int>& p){
	return a.first <= p.first and b.first >= p.first and a.second >= p.second and b.second <= p.second;	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		
		pii_pii line;
		cin >> line.first.first >> line.first.second >> line.second.first >> line.second.second;
		
		if(line.first > line.second){
			swap(line.first, line.second);
		}
		
		pair<int, int> left_top;
		pair<int, int> right_bottom;
		cin >> left_top.first >> left_top.second >> right_bottom.first >> right_bottom.second;
		
		auto temp = left_top;
		
		left_top = make_pair(min(left_top.first, right_bottom.first), max(left_top.second, right_bottom.second));
		right_bottom = make_pair(max(temp.first, right_bottom.first), min(temp.second, right_bottom.second));
		
		if(check(left_top, right_bottom, line.first) or check(left_top, right_bottom, line.second)){
			cout << "T\n";
			continue;
		}
		
		pii_pii v1 = make_pair(make_pair(left_top.first, right_bottom.second), left_top);
		pii_pii v2 = make_pair(left_top, make_pair(right_bottom.first, left_top.second));
		pii_pii v3 = make_pair(right_bottom, make_pair(right_bottom.first, left_top.second));
		pii_pii v4 = make_pair(make_pair(left_top.first, right_bottom.second), right_bottom);
		
		if(is_intersect(line, v1) or is_intersect(line, v2) or is_intersect(line, v3) or is_intersect(line, v4)){
			cout << "T\n";
		}else{
			cout << "F\n";
		}
	}
	
	return 0;
}