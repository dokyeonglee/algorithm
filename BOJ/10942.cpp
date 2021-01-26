#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n + 1);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
	
	for(int i = 0; i <= n; i++){
		dp[i][i] = true;
	}

	for(int i = 0; i < n - 1; i++){
		if(arr[i] == arr[i + 1]){
			dp[i][i + 1] = true;
		}
	}
	
	for(int l = 3; l <= n; l++){
		for(int i = 0; i < n - l + 1; i++){
			int j = i + l - 1;
			if(dp[i + 1][j - 1] and arr[i] == arr[j]){
				dp[i][j] = true;
			}
		}
	}
	
	int m;
	cin >> m;
	
	for(int i = 0; i < m; i++){
		
		int s, e;
		cin >> s >> e;
		
		cout << dp[s - 1][e - 1] << "\n";
		
	}

	return 0;
}