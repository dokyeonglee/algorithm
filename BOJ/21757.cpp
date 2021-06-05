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
	
	if(psum[n] % 4 != 0){
		cout << 0;
	}else{
		
		vector<vector<long long>> dp(n + 1, vector<long long>(4));
		dp[0][0] = 1;
		
		for(int i = 1; i <= n; i++){
			dp[i][0] = 1;
			for(int j = 1; j <= 3; j++){
				dp[i][j] = dp[i - 1][j];
				if(psum[n] / 4 * j == psum[i]){
					dp[i][j] += dp[i - 1][j - 1];
				}
			}
		}
		
		cout << dp[n - 1][3];
		
	}
	
	return 0;
}