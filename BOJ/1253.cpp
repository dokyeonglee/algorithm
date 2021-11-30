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
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		int left = 0;
		int right = n - 1;
		while(left < right){
			int sum = arr[left] + arr[right];
			if(sum == arr[i]){
				if(left != i and right != i){
					answer++;
					break;
				}else if(left == i){
					left++;
				}else if(right == i){
					right--;
				}
			}else if(sum < arr[i]){
				left++;
			}else{
				right--;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}