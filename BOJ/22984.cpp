#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	double answer = 0;
	vector<double> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		answer += arr[i];
	}
	
	for(int i = 0; i < n - 1; i++){
		answer += arr[i] * (1 - arr[i + 1]) + arr[i + 1] * (1 - arr[i]);
	}
	
	cout << fixed;
	cout.precision(16);
	
	cout << answer;
	return 0;
}