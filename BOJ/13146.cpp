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
	
	long long answer = 0;
	int m = 0;
	for(int i = 0; i < arr.size() - 1; i++){
		answer += max(arr[i + 1] - arr[i], 0);
		m = max(m, arr[i]);
	}
	
	cout << answer + max(m, arr.back()) - arr.back();
	
	return 0;
}