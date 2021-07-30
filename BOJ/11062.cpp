#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[1001][1001][2];

int solve(vector<int>& card, int left, int right, int player){
	
	if(left == right){
		return card[left] * (1 ^ player);
	}
	
	int& ret = dp[left][right][player];
	
	if(ret != -1){
		return dp[left][right][player];
	}
	
	
	if(player == 0){
		return ret = max(card[left] + solve(card, left + 1, right, 1), card[right] + solve(card, left, right - 1, 1));
	}else{
		return ret = min(solve(card, left + 1, right, 0), solve(card, left, right - 1, 0));
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> card(n);
		for(int i = 0; i < n; i++){
			cin >> card[i];
		}
		
		memset(dp, -1, sizeof(dp));
		cout << solve(card, 0, n - 1, 0) << "\n";
	}
	
	return 0;
}