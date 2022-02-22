#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long > arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	long long answer = 0;
	long long two = 1;
	
	for(int i = 0; i < 30; i++){
		int cnt = 0;
		bool check = false;
		for(int j = 0; j < n; j++){
			if(arr[j] & (1ll << i)){
				check = !check;
			}
			if(check){
				cnt++;
			}
		}
		for(int j = 0; j < n; j++){
			answer += two * cnt;
			if(arr[j] & (1ll << i)){
				cnt = n - j - cnt;
			}
		}
		two *= 2;
	}
	
	cout << answer;
	
	return 0;
}