#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int k;
	cin >> k;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	vector<int> diff(n - 1);
	for(int i = 0; i < n - 1; i++){
		diff[i] = arr[i + 1] - arr[i];
	}
	
	sort(diff.begin(), diff.end());
	
	int answer = 0;
	for(int i = 0; i < n - k; i++){
		answer += diff[i];
	}
	
	cout << answer;
	
	return 0;
}