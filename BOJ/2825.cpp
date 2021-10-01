#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<long long> cnt(1024);
	for(int i = 0; i < n; i++){
		long long x;
		long long bit = 0;
		cin >> x;
		while(x > 0){
			bit |= (1 << (x % 10));
			x /= 10;
		}
		cnt[bit]++;
	}
	
	long long answer = 0;
	for(int i = 0; i < 1024; i++){
		answer += cnt[i] * (cnt[i] - 1) / 2;
		for(int j = i + 1; j < 1024; j++){
			if(i & j){
				answer += cnt[i] * cnt[j];
			}
		}
	}
	
	cout << answer;
	
	return 0;
}