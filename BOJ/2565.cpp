#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		arr[i] = make_pair(x, y);
	}
		
	sort(arr.begin(), arr.end());
	
	vector<int> v(1, -1);
	for(int i = 0; i < n; i++){
		if(v.back() < arr[i].second){
			v.push_back(arr[i].second);
		}else{
			auto it = lower_bound(v.begin(), v.end(), arr[i].second);
			*it = arr[i].second;
		}
	}
	
	cout << n - (v.size() - 1);
	
	return 0;
}