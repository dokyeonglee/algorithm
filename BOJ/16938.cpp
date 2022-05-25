#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int answer = 0;
	for(int i = 0; i < (1 << n); i++){
		int sum = 0;
		int _min = 987654321;
		int _max = -1;
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				sum += arr[j];
				_min = min(_min, arr[j]);
				_max = max(_max, arr[j]);
			}
		}
		if(sum >= l and sum <= r and _max - _min >= x){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}