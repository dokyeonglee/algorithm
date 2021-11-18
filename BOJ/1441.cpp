#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, l, r;
	cin >> n >> l >> r;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	long long answer = r - l + 1;
	
	for(int i = 0; i < (1 << n); i++){
		
		long long lcm = 1;
		
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				lcm = lcm * arr[j] / gcd(lcm, arr[j]);
			}
		}
		
		long long cnt = r / lcm - (l - 1) / lcm;
		
		if(__builtin_popcount(i) % 2){
			answer += cnt;
		}else{
			answer -= cnt;
		}
	}
	
	cout << answer;
	
	return 0;
}