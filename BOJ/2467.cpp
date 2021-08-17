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
	
	
	int left = 0;
	int right = n - 1;
	int answer_value = abs(arr[left] + arr[right]);
	int answer_left = left;
	int answer_right = right;
	
	while(left < right){
		int value = arr[left] + arr[right];
		if(abs(value) < answer_value){
			answer_value = abs(value);
			answer_left = left;
			answer_right = right;
		}
		if(value < 0){
			left++;
		}else{
			right--;
		}
	}
	
	cout << arr[answer_left] << " " << arr[answer_right];
	
	return 0;
}