#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(m + 1, vector<int>(n + 1));
	vector<vector<int>> dp(arr);
	vector<vector<int>> _answer(arr);
		
	for(int i = 1; i <= n; i++){
		int money;
		cin >> money;
		for(int j = 1; j <= m; j++){
			cin >> arr[j][money];
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int money = 1; money <= n; money++){
			for(int j = 0; j <= money; j++){
				int earn = dp[i - 1][money - j] + arr[i][j];
				if(earn > dp[i][money]){
					dp[i][money] = earn;
					_answer[i][money] = j;
				}
			}
		}
	}
	
	cout << dp[m][n] << "\n";
	
	int money = n;
	vector<int> answer;
	
	for(int i = m; i >= 1; i--){
		answer.push_back(_answer[i][money]);
		money -= _answer[i][money];
	}
	
	for(int i = answer.size() - 1; i >= 0; i--){
		cout << answer[i] << " ";
	}
	
	return 0;
}