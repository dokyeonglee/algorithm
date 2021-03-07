#include <iostream>
#include <vector>

using namespace std;

void fib(int n, vector<long long>& dp){
	
	if(n == 1){
		fill(dp.begin(), dp.begin() + 3, 1);
		return;
	}
	
	vector<long long> temp(4);
	
	fib(n / 2, temp);
	
	for(int i = 0; i < 4; i++){
		dp[i] = (temp[i & 2] * temp[i & 1] + temp[i | 1] * temp[i | 2]) % 10000;
	}
	
	if(n % 2 == 1){
		dp[0] = (dp[0] + dp[1]);
		dp[1] = (dp[0] - dp[1] + 10000) % 10000;
		dp[2] = (dp[2] + dp[3]);
		dp[3] = (dp[2] - dp[3] + 10000) % 10000;
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		
		int n;
		cin >> n;
		
		if(n == -1){
			break;
		}
		
		vector<long long> dp(4);
		
		if(n > 0){
			fib(n, dp);
		}
		
		cout << dp[1] << '\n';
		
	}
	
	return 0;
}