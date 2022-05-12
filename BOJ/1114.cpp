#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int l, k, c;
	cin >> l >> k >> c;
	
	vector<int> arr(k + 2);
	for(int i = 1; i <= k; i++){
		cin >> arr[i];
	}
	arr[k + 1] = l;
	
	sort(arr.begin(), arr.end());
		
	int left = 0;
	int right = l;
	int answer = 0;
	int idx = 0;
	
	while(left <= right){
		
		int mid = (left + right) / 2;
		int cut_cnt = 0;
		int sum = 0;
		int _idx = -1;
		bool possible = true;
		
		for(int i = k; i >= 0; i--){
			if(sum + arr[i + 1] - arr[i] > mid){
				cut_cnt++;
				sum = arr[i + 1] - arr[i];
				if(sum > mid){
					possible = false;
				}
				_idx = i + 1;
			}else{
				sum += arr[i + 1] - arr[i];
			}
		}
		if(possible and cut_cnt <= c){
			right = mid - 1;
			answer = mid;
			idx = cut_cnt < c ? 1 : _idx;
		}else{
			left = mid + 1;
		}
	}
	
	cout << answer << " " << arr[idx];
	
	return 0;
}