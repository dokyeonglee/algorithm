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
	
	int answer = 1;
	
	if(n < 3){
		cout << n;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i + 1; j--){
			if(arr[i] + arr[i + 1] > arr[j]){
				answer = max(answer, j - i + 1);
				break;
			}
		}
	}
	
	if(answer == 1 and n >= 3){
		answer = 2;
	}
	
	cout << answer;
	
	return 0;
}