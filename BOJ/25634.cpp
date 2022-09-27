#include <iostream>
#include <vector>

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
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1){
			answer += arr[i];
			arr[i] *= -1;
		}
	}
	
	int max_sum = -5001;
	int prev = 0;
	for(int i = 0; i < n; i++){
		prev += arr[i];
		max_sum = max(max_sum, prev);
		prev = max(prev, 0);
	}
	
	cout << answer + max_sum;
	
	return 0;
}