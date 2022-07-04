#include <iostream>
#include <vector>
#include <algorithm>

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
	
	vector<int> diff(n - 1);
	for(int i = 1; i < n; i++){
		diff[i - 1] = arr[i] - arr[i - 1];
	}
	
	sort(diff.begin(), diff.end());
	
	long long answer = 0;
	for(int i = 0; i < n - k ; i++){
		answer += diff[i];
	}
	
	cout << answer;
	
	return 0;
}