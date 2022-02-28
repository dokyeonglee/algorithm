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
	
	long long answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			long long x = arr[i] + arr[j];
			answer += upper_bound(arr.begin() + j + 1, arr.end(), -x) - lower_bound(arr.begin() + j + 1, arr.end(), -x);
		}
	}
	
	cout << answer;
	
	return 0;
}