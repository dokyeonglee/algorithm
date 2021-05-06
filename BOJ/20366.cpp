#include <iostream>
#include <algorithm>
#include <vector>

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
	
	int answer = 1987654321;
	
	for(int i = 0; i < n; i++){
		for(int j = i + 3; j < n; j++){
			
			int left = i + 1;
			int right = j - 1;
			
			while(left < right){
				int diff = arr[i] + arr[j] - arr[left] - arr[right];
				answer = min(answer, abs(diff));
				if(diff < 0){
					right--;
				}else{
					left++;
				}
			}
			
		}
	}
	
	cout << answer;
	
	return 0;
}