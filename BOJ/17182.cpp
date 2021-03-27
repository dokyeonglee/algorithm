#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> dp(n, vector<int>(n));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> dp[i][j];		
		}
	}
	
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);			
			}
		}
	}

	vector<int> order;
	for(int i = 0; i < n; i++){
		if(i != k){
			order.push_back(i);
		}	
	}
	
	int answer = 987654321;
	
	do{
		
		int cost = 0;
		int curr_pos = k;
		
		for(int i = 0; i < order.size(); i++){
			cost += dp[curr_pos][order[i]];
			curr_pos = order[i];
		}
		
		answer = min(answer, cost);
		
	}while(next_permutation(order.begin(), order.end()));
	
	cout << answer;
	
	return 0;
}