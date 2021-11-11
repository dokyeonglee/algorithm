#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string str1, str2;
	cin >> str1 >> str2;
	
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
	for(int i = 3; i <= str1.size(); i += 3){
		for(int j = 3; j <= str2.size(); j += 3){
			if(str1.substr(i - 3, 3) == str2.substr(j - 3, 3)){
				dp[i][j] = dp[i - 3][j - 3] + 1;
			}else{
				dp[i][j] = max(dp[i][j - 3], dp[i - 3][j]);
			}
		}
	}
	
	cout << dp[str1.size()][str2.size()];
	
	return 0;
}