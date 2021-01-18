#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	
	int n, k;
	cin >> n >> k;
	
	int lo = 1; 
	int hi = k;
	
	int answer = 0;
	
	while(lo <= hi){
		
		int mid = (lo + hi) / 2;
		int cnt = 0;
		
		for(int i = 1; i <= n; i++){
			cnt += min(mid / i, n);
		}
		
		if(cnt < k){
			lo = mid + 1;
		}else{
			hi = mid - 1;
			answer = mid;
		}
	}
	
	cout << answer << endl;
	
	return 0;
}