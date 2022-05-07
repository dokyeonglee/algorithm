#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int c, n;
	cin >> c >> n;
	
	vector<int> dp(100001);
	
	for(int i = 0; i < n; i++){
		int cost, value;
		cin >> cost >> value;
		for(int j = 1; j <= 100000; j++){
			if(j >= cost){
				dp[j] = max(dp[j], dp[j - cost] + value);
			}
		}
	}
	
	for(int i = 1; i <= 100000; i++){
		if(dp[i] >= c){
			cout << i;
			return 0;
		}
	}
	
	return 0;
}