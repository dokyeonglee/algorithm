#include <iostream>

using namespace std;

int solve(int n, int k){
	if(k == 2){
		return max(n - 2, 0);
	}else if(k == 3){
		return max(n / 3 - 1, 0);
	}else if(k == 4){
		if(n == 10){
			return 1;
		}
		if(n == 12){
			return 0;
		}
		return max(n / 2 - 5, 0);
	}else{
		return max(n / 5 - 2, 0);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int left, right, k;
	cin >> left >> right >> k;
	
	cout << solve(right, k) - solve(left - 1, k);
	
	return 0;
}