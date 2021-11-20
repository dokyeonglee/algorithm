#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	long long answer = 0;
	for(int i = 1; i < (1 << n); i++){
		long long mul = 1;
		int cnt = __builtin_popcount(i);
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				mul *= arr[j];
			}
		}
		if(cnt % 2 == 1){
			answer += m / mul;
		}else{
			answer -= m / mul;
		}
	}
	
	cout << answer;
	
	return 0;
}