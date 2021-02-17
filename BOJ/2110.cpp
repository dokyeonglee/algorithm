#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, c;
	cin >> n >> c;
	
	vector<int> house_pos(n);
	for(int i = 0; i < n; i++){
		cin >> house_pos[i];
	}
	
	sort(house_pos.begin(), house_pos.end());

	int lo = 1;
	int hi = house_pos.back() - house_pos.front();
	int answer = 0;
	
	while(lo <= hi){
		
		int mid = (lo + hi) / 2;
		int cnt = 1;
		int router_pos = house_pos.front();
		
		for(int i = 1; i < n; i++){
			if(house_pos[i] - router_pos >= mid){
				cnt++;
				router_pos = house_pos[i];
			}
		}
		
		if(cnt >= c){
			answer = mid;
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
		
	}
	
	cout << answer;
	
	return 0;
}