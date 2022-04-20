#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<bool> dp(1000001, false);

	for(int i = 1; i * i <= 1000000; i++){
		dp[i * i] = true;
	}
	
	for(int i = 1; i <= 1000000; i++){
		if(!dp[i]){
			for(int j = 1; j * j + i <= 1000000; j++){
				dp[j * j + i] = true;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(dp[x]){
			cout << "koosaga\n";
		}else{
			cout << "cubelover\n";
		}
	}
	
	return 0;
}