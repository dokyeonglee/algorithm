#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string encrypted_str;
	cin >> encrypted_str;
	
	vector<int> arr(encrypted_str.size() + 1);
	
	for(int i = 0; i < encrypted_str.size(); i++){
		arr[i + 1] = encrypted_str[i] - '0';
	}
	
	vector<int> dp(encrypted_str.size() + 1);
	
	dp[0] = 1;
	
	for(int i = 1; i <= encrypted_str.size(); i++){
		
		if(arr[i] != 0){
			dp[i] = (dp[i - 1] + dp[i]) % 1000000;	
		}
		
		int temp = arr[i - 1] * 10 + arr[i];
		
		if(temp >= 10 and temp <= 26){
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;	
		}
		
	}
	
	cout << dp[encrypted_str.size()] << endl;
	
	return 0;
}