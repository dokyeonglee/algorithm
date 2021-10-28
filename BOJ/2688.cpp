#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	vector<vector<long long>> dp(65, vector<long long>(10));
	
	for(int i = 0; i <= 9; i++){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= 64; i++){
		for(int j = 0; j <= 9; j++){
			for(int k = j; k <= 9; k++){
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	
	while(T--){
		int n;
		cin >> n;
		long long answer = 0;
		for(int i = 0; i <= 9; i++){
			answer += dp[n][i];
		}
		cout << answer << "\n";
	}
	
	return 0;
}