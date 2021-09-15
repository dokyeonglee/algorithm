#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int money) {
	
	vector<int> dp(money + 1);
	for(int i = 1; i < weight.size(); i++){
		for(int j = 0; j <= money; j++){
			if(weight[i] <= j){
				dp[j] = max(dp[j - weight[i]] + value[i], dp[j]);
			}
		}
	}
	
	int result = 0;
	
	for(int i = 0; i <= money; i++){
		result = max(result, dp[i] - (int)(lower_bound(dp.begin(), dp.end(), dp[i]) - dp.begin()));
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int c, d, m;
	cin >> c >> d >> m;
	
	vector<vector<int>> arr(d + 1, vector<int>(c + 1));
	for(int i = 1; i <= c; i++){
		for(int j = 1; j <= d; j ++){
			cin >> arr[j][i];
		}
	}
	
	int answer = m;
	
	for(int i = 1; i <= d - 1; i++){
		answer += knapsack(arr[i], arr[i + 1], answer);
	}
	
	cout << answer;
	
	return 0;
}