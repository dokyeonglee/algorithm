#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<vector<int>> dp(n, vector<int>(2));
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	
	int answer = 1;
	
	for(int i = 1; i < n; i++){
		if(arr[i] < arr[i - 1]){
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = 1;
		}else if(arr[i] > arr[i - 1]){
			dp[i][0] = 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}else{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1] + 1;
		}
		
		answer = max(answer, max(dp[i][0], dp[i][1]));
	}
	
	cout << answer;
	
	return 0;
}