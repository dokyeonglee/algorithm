#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int answer = 0;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		answer += arr[i];
	}
	
	sort(arr.begin(), arr.end());

	for(int i = 0; i < n - 1; i += 2){
		if(arr[i] < 1 and arr[i + 1] < 1){
			answer += arr[i] * arr[i + 1] - arr[i] - arr[i + 1];
		}else{
			break;
		}
	}
	
	for(int i = n - 1; i > 0; i -= 2){
		if(arr[i] > 1 and arr[i - 1] > 1){
			answer += arr[i] * arr[i - 1] - arr[i] - arr[i - 1];
		}else{
			break;
		}
	}
	
	cout << answer;
		
	return 0;
}