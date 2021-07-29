#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, h;
	cin >> n >> m >> h;
	cin.ignore(1);
	
	vector<vector<int>> H(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(h + 1));
	
	for(int i = 1; i <= n; i++){
		string str;
		getline(cin, str);
		int num = 0;
		for(int j = 0; j < str.size(); j++){
			if(str[j] == ' '){
				H[i].push_back(num);
				num = 0;
			}else{
				num = num * 10 + str[j] - '0';
			}
		}
		if(num != 0){
			H[i].push_back(num);
		}
	}
	
	for(int i = 0; i <= n; i++){
		dp[i][0] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= h; j++){
			for(int k = 0; k < H[i].size(); k++){
				if(j >= H[i][k]){
					dp[i][j] += dp[i - 1][j - H[i][k]];
					dp[i][j] %= 10007;
				}
			}
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}
	
	cout << dp[n][h];
	
	return 0;
}