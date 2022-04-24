#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> prime;
	vector<bool> is_prime(40001, true);
	is_prime[1] = false;
	
	for(int i = 2; i * i <= 40000; i++){
		if(is_prime[i]){
			for(int j = i * i; j <= 40000; j += i){
				is_prime[j] = false;
			}
		}
	}
	
	for(int i = 2; i <= 40000; i++){
		if(is_prime[i]){
			prime.push_back(i);
		}
	}
	
	int n;
	cin >> n;
	
	vector<long long> dp(n + 1);
	dp[0] = 1;
	
	for(int i = 0; i < prime.size(); i++){
		for(int j = prime[i]; j <= n; j++){
			dp[j] = (dp[j] + dp[j - prime[i]]) % 123456789;
		}
	}
	
	cout << dp[n];
	
	return 0;
}