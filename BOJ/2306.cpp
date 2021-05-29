#include <iostream>
#include <vector>

using namespace std;

int solve(string& str, int l, int r, vector<vector<int>>& dp){
	
	if(l >= r){
		return 0;
	}
	
	int& result = dp[l][r];
	
	if(result != -1){
		return result;
	}
	
	for(int i = l; i < r; i++){
		result = max(result, solve(str, l, i, dp) + solve(str, i + 1, r, dp));
	}
	
	if((str[l] == 'a' and str[r] == 't') or (str[l] == 'g' and str[r] == 'c')){
		result = max(result, solve(str, l + 1, r - 1, dp) + 2);
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str;
	cin >> str;
	
	vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, -1));
	
	cout << solve(str, 0, str.size() -1, dp);
	
	return 0;
}