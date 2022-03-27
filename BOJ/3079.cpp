#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	
	vector<long long> arr(n);
	for(int i = 0; i < n; i++){
		cin  >> arr[i];
	}
	
	long long left = 0;
	long long right = 1e9 * n;
	long long answer = 1e18;
	
	while(left <= right){
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for(long long a : arr){
			cnt += mid / a;
		}
		if(cnt < m){
			left = mid + 1;
		}else{
			answer = min(answer, mid);
			right = mid - 1;
		}
	}
	
	cout << answer;
	
	return 0;
}