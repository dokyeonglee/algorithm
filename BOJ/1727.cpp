#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> man(n + 1);
	vector<int> woman(m + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> man[i];
	}
	
	for(int i = 1; i <= m; i++){
		cin >> woman[i];
	}
	
	sort(man.begin(), man.end());
	sort(woman.begin(), woman.end());
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j - 1] + abs(man[i] - woman[j]);
			if(i > j){
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if(i < j){
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			}
		}
		
	}
	
	cout << dp[n][m];
	
	return 0;
}