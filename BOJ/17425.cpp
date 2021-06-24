#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	vector<long long> f(1000001, 1);
	
	for(int i = 2; i <= 1000000; i++){
		for(int j = 1; i * j <= 1000000; j++){
			f[i * j] += i;
		}
	}
	
	vector<long long> dp(1000001);
	
	for(int i = 1; i <= 1000000; i++){
		dp[i] = dp[i - 1] + f[i];
	}
	
	while(t--){
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
}