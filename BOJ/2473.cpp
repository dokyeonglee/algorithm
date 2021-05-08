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
	
	vector<int> answer(3);
	long long min_sum = 3987654321;
	
	for(int i = 0; i < n - 2; i++){
		
		int left = i + 1;
		int right = n - 1;
		
		while(left < right){
			
			long long sum = (long long)arr[i] + arr[left] + arr[right];
			
			if(abs(sum) < min_sum){
				min_sum = abs(sum);
				answer[0] = arr[i];
				answer[1] = arr[left];
				answer[2] = arr[right];
			}
			
			if(sum < 0){
				left++;
			}else if(sum > 0){
				right--;
			}else{
				i = n - 2;
				break;
			}
			
		}
	}
	
	cout << answer[0] << " " << answer[1] << " " << answer[2];
	
	return 0;
}