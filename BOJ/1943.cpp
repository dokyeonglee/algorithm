#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	for(int t = 0; t < 3; t++){
		
		int n;
		cin >> n;
		
		int money = 0;
		vector<pair<int, int>> coin(n);
		
		for(int i = 0; i < n; i++){
			cin >> coin[i].first >> coin[i].second;
			money += coin[i].first * coin[i].second;
		}
		
		if(money % 2){
			cout << 0 << "\n";
			continue;
		}
		
		vector<int> dp(money / 2 + 1);
		dp[0] = 1;
		
		for(int i = 0; i < n; i++){
			
			int value = coin[i].first;
			int amount = coin[i].second;
			
			for(int j = money / 2; j >= value; j--){
				if(dp[j - value]){
					for(int k = 0; k < amount and j + value * k <= money / 2; k++){
						dp[j + value * k] = 1;
					}
				}
			}
		}
		
		cout << dp[money / 2] << "\n";
		
	}
		
	return 0;
}