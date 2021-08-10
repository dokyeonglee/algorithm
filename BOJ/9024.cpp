#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		
		sort(arr.begin(), arr.end());
		
		int left = 0;
		int right = n - 1;
		
		int nearest = 987654321;
		int answer = 0;
		
		while(left < right){

			if(abs(k - arr[left] - arr[right]) < nearest){
				nearest = abs(k - arr[left] - arr[right]);
				answer = 1;
			}else if(abs(k - arr[left] - arr[right]) == nearest){
				answer++;
			}
			if(arr[left] + arr[right] == k){
				left++;
				right--;
			}else if(arr[left] + arr[right] < k){
				left++;
			}else{
				right--;
			}		
		}
		cout << answer << "\n";
	}
	
	
	return 0;
}