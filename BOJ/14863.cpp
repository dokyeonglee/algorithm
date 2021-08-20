#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	pair<int, int> walk;
	pair<int, int> bicycle;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	
	for(int i = 1; i <= n; i++){
		cin >> walk.first >> walk.second >> bicycle.first >> bicycle.second;
		if(i == 1){
			dp[i][walk.first] = walk.second;
			dp[i][bicycle.first] = max(dp[i][bicycle.first], bicycle.second);
		}else{
			for(int j = 0; j <= k; j++){
				if(dp[i - 1][j]){
					if(walk.first + j <= k){
						dp[i][j + walk.first] = max(dp[i][j + walk.first], dp[i - 1][j] + walk.second);
					}
					if(bicycle.first + j <= k){
						dp[i][j + bicycle.first] = max(dp[i][j + bicycle.first], dp[i - 1][j] + bicycle.second);
					}
				}
			}
		}
	}
	
	cout << *max_element(dp[n].begin(), dp[n].end());
	
	return 0;
}