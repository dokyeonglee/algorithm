#include <iostream>
#include <vector>

using namespace std;

const int match_num_to_digit[] = {-1, -1, 1, 7, 4, 2, 0, 8, 10};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<long long> dp(101);
	
	for(int i = 1; i < 9; i++){
		dp[i] = match_num_to_digit[i];
	}
	
	dp[6] = 6;
	
	for(int i = 9; i < 101; i++){
		
		dp[i] = dp[i - 2] * 10 + match_num_to_digit[2];
		
		for(int j = 3; j < 8; j++){
			dp[i] = min(dp[i], dp[i - j] * 10 + match_num_to_digit[j]);
		}
	}
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		long long small = dp[n];
		string large = "";
		
		if(n % 2 == 1){
			large += '7';
			n -= 3;
		}
		
		while(n > 0){
			large += '1';
			n -= 2;
		}
		
		cout << small << " " << large << '\n';
	}
	
	return 0;
}