#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<double> arr(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	int j, c;
	cin >> j >> c;
	
	for(int i = 0; i < c; i++){
		arr[0] += arr[0] / sum * j;
		sum += j;
	}
	
	cout << fixed;
	cout.precision(10);
	cout << arr[0];
	
	return 0;
}