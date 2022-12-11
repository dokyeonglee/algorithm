#include <iostream>
#include <vector>

using namespace std;

void solve(string& str1, string& str2, vector<vector<int>>& dp, int idx1, int idx2){
	if(idx1 == 0 or idx2 == 0){
		return;
	}
	if(str1[idx1 - 1] == str2[idx2 - 1]){
		solve(str1, str2, dp, idx1 - 1, idx2 - 1);
		cout << str1[idx1 - 1];
	}else{
		if(dp[idx1][idx2 - 1] == dp[idx1][idx2]){
			solve(str1, str2, dp, idx1, idx2 - 1);
		}else{
			solve(str1, str2, dp, idx1 - 1, idx2);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1;
	string str2;
	
	cin >> str1 >> str2;
	
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
	for(int i = 1; i <= str1.size(); i++){
		for(int j = 1; j <= str2.size(); j++){
			if(str1[i - 1] == str2[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	solve(str1, str2, dp, str1.size(), str2.size());
	
	return 0;
}