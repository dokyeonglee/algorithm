#include <iostream>
#include <vector>

using namespace std;


int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<double>> arr(n, vector<double>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	
	vector<double> dp(1 << n);
	dp[0] = 1;
	
	for(int i = 0; i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if((i & (1 << j)) == 0){
				dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * arr[j][__builtin_popcount(i)] / 100);
			}
		}
	}
	
	cout.precision(6);
	cout << fixed;
	
	cout << dp[(1 << n) - 1] * 100;
	
	return 0;
}