#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> cost;
	vector<long long> value;
	
	for(int i = 1; i <= n; i++){
		int c, v, a;
		cin >> c >> v >> a;
		int x = 1;
		while(a > 0){
			int xx = min(x, a);
			cost.push_back(c * xx);
			value.push_back(v * xx);
			x <<= 1;
			a -= xx;
		}
	}
	
	vector<vector<long long>> dp(cost.size() + 1, vector<long long>(m + 1));
	long long answer = 0;
	for(int i = 1; i <= cost.size(); i++){
		for(int j = 1; j <= m; j++){
			if(cost[i - 1] <= j){
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i - 1]] + value[i - 1]);
			}else{
				dp[i][j] = dp[i - 1][j];
			}
			answer = max(answer, dp[i][j]);
		}
	}
	
	cout << answer;
		
	return 0;
}