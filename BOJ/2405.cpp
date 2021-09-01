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
	
	int answer = 0;
	for(int i = 0; i < n - 2; i++){
		answer = max(answer, abs(arr[i] - 2 * arr[i + 1] + arr[n - 1]));
	}
	for(int i = 1; i < n - 1; i++){
		answer = max(answer, abs(-arr[0] + 2 * arr[i] - arr[i + 1]));
	}
	
	cout << answer;
	
	return 0;
}