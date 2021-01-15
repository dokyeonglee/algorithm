#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> T(n + 1);
	vector<int> P(n + 1);
	
	vector<int> dp(n + 6);

	for(int i = 1; i <= n; i++){
		cin >> T[i] >> P[i];
		int next_T = i + T[i];
		if(next_T <= n + 1){
			dp[next_T] = max(dp[next_T], dp[i] + P[i]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
		
	}
	
	cout << *max_element(dp.begin(), dp.end()) << endl;
	
	return 0;
}