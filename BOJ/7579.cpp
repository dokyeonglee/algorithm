#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int n, m;
	cin >> n >> m;
	
	vector<int> memory(n + 1);
	vector<int> cost(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> memory[i];
	}
	
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(10001));
	int answer = 1987654321;
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 10000; j++){
			if(cost[i] <= j){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);	
			}else{
				dp[i][j] = dp[i - 1][j];
			}
			if(dp[i][j] >= m){
				answer = min(answer, j);
			}
		}
	}
	
	cout << answer;
	
	return 0;
}