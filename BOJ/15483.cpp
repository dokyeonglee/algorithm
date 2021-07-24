#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string src, dst;
	cin >> src >> dst;
	
	vector<vector<int>> dp(src.size() + 1, vector<int>(dst.size() + 1));
	
	for(int i = 0; i <= src.size(); i++){
		dp[i][0] = i;
	}
	
	for(int i = 0; i <= dst.size(); i++){
		dp[0][i] = i;
	}
	
	for(int i = 1; i <= src.size(); i++){
		for(int j = 1; j <= dst.size(); j++){
			if(src[i - 1] == dst[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
		}
	}
	
	cout << dp[src.size()][dst.size()];
	
	return 0;
}