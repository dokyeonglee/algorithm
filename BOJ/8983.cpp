#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n, l;
	cin >> m >> n >> l;
	
	vector<int> lane(m);
	
	for(int i = 0; i < m; i++){
		cin >> lane[i];
	}
	
	sort(lane.begin(), lane.end());
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		
		int x, y;
		cin >> x >> y;
		
		if(y > l){
			continue;
		}
		
		int lo = 0;
		int hi = m - 1;
		int left = x + y - l;
		int right = x - y + l;
		
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			if(left <= lane[mid] and lane[mid] <= right){
				answer++;
				break;
			}else if(lane[mid] < left){
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}
		
	}
	
	cout << answer;
		
	return 0;
}