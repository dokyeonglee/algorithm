#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> psum(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		int left = i;
		int right = n;
		while(left <= right){
			int mid = (left + right) / 2;
			int clockwise_sum = psum[mid] - psum[i - 1];
			int anti_clockwise_sum = psum[n] - clockwise_sum;
			if(clockwise_sum < anti_clockwise_sum){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
			answer = max(answer, min(clockwise_sum, anti_clockwise_sum));
		}
	}
	
	cout << answer;
	
	return 0;
}