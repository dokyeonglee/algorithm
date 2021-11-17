#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int left = 0;
	int right = 20 * n;
	int answer = 0;
	
	while(left <= right){
		
		int mid = (left + right) / 2;
		int temp = 0;
		int sum = 0;
		
		for(int i = 0; i < n; i++){
			sum += arr[i];
			if(sum >= mid){
				sum = 0;
				temp++;
			}
		}
		if(temp >= k){
			left = mid + 1;
			answer = max(answer, mid);
		}else{
			right = mid - 1;
		}
	}
	
	cout << answer;
	
	return 0;
}