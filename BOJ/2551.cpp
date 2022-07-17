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
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr.begin(), arr.end());
	cout << arr[(n - 1) / 2] << " " << sum / n + (sum % n * 2 > n);
	
	return 0;
}