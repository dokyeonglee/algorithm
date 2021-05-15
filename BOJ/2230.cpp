#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	int answer = 2000000001;
	int left = 0;
	int right = 1;
	
	while(left <= right and right < n){
		
		if(arr[right] - arr[left] < m){
			right++;	
		}else{
			answer = min(answer, arr[right] - arr[left]);
			left++;
		}
		
	}
	
	cout << answer;
	
	return 0;
}