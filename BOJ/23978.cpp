#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, k;
	cin >> n >> k;
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i]; 
	}
	
	long long left = 0;
	long long right = k;
	long long answer;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		__int128 result = 0;
		for(int i = 0; i < n - 1; i++){
			long long t = min(arr[i + 1] - arr[i], mid);
			result += (__int128)t * (2 * mid - (t - 1)) / 2;
		}
		result += (__int128)mid * (mid + 1) / 2;
		if(result >= k){
			right = mid - 1;
			answer = mid;
		}else{
			left = mid + 1;
		}
	}
	
	cout << answer;
	
	return 0;
}