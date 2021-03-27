#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	int left = 0;
	int right = n - 1;
	int min = 2000000001;
	
	pair<int, int> answer;
	
	while(left < right){
		if(min >= abs(arr[left] + arr[right])){
			answer.first = arr[left];
			answer.second = arr[right];
			min = abs(arr[left] + arr[right]);
		}
		if(arr[left] + arr[right] <= 0){
			left++;
		}else if(arr[left] + arr[right] > 0){
			right--;
		}
	}
	
	cout << answer.first << " " << answer.second;
	
	return 0;
}