#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
	
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d, n, m;
	cin >> d >> n >> m;
		
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	arr.push_back(0);
	sort(arr.begin(), arr.end());
	arr.push_back(d);
		
	int left = 1;
	int right = d;
	int answer = 0;
	while(left <= right){
		int mid = (left + right) / 2;
		int cnt = 0;
		int idx = 0;
		for(int i = 1; i < arr.size(); i++){
			if(arr[i] - arr[idx] < mid){
				cnt++;
			}else{
				idx = i;
			}
			if(cnt > m){
				break;
			}
		}
		if(cnt <= m){
			answer = mid;
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	
	cout << answer;
	
	return 0;
}