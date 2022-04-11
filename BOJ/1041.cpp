#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin >> n;
	
	vector<int> arr(6);
	int _max = -1;
	int sum = 0;
	
	for(int i = 0; i < 6; i++){
		cin >> arr[i];
		sum += arr[i];
		_max = max(_max, arr[i]);
	}
	
	if(n == 1){
		cout << sum - _max;
	}else{
		
		arr[0] = min(arr[0], arr[5]);
		arr[1] = min(arr[1], arr[4]);
		arr[2] = min(arr[2], arr[3]);
		
		sort(arr.begin(), arr.begin() + 3);
		
		long long a = arr[0];
		long long b = a + arr[1];
		long long c = b + arr[2];
		
		cout << c * 4 + b * (4 * (n - 2) + 4 * (n - 1)) + a * (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2));
		
	}
	
	
	return 0;
}