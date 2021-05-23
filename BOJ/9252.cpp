#include <iostream>
#include <vector>

using namespace std;

void print_lcs(string& a, string& b, int i, int j, vector<vector<int>>& dp){
	if(dp[i][j] == 0){
		return;
	}
	if(a[i - 1] == b[j - 1]){
		print_lcs(a, b, i - 1, j - 1, dp);
		cout << a[i - 1];
	}else{
		dp[i - 1][j] > dp[i][j - 1] ? print_lcs(a, b, i - 1, j, dp) : print_lcs(a, b, i, j - 1, dp);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
	
	for(int i = 0; i < str1.size(); i++){
		for(int j = 0; j < str2.size(); j++){
			if(str1[i] == str2[j]){
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}else{
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}
	
	cout << dp[str1.size()][str2.size()] << "\n";
	print_lcs(str1, str2, str1.size(), str2.size(), dp);
	
	return 0;
}