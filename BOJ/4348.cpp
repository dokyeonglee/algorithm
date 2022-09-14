#include <iostream>
#include <vector>

using namespace std;

int total;

bool dfs(vector<int>& arr, vector<bool>& dp, int bit, int x){
	
	int n = arr.size();
	
	if(bit == (1 << n) - 1){
		return true;
	}

	if(dp[bit]){
		return false;
	}
	
	dp[bit] = true;
	
	for(int i = 0; i < n; i++){
		if((bit & (1 << i)) == 0){
			if(x == arr[i]){
				if(dfs(arr, dp, bit | (1 << i), total / 4)){
					return true;
				}
			}else if(x > arr[i]){
				if(dfs(arr, dp, bit | (1 << i), x - arr[i])){
					return true;
				}
			}
		}
	}
	
	return false;
		
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n;
		cin >> n;
		
		vector<int> arr(n);
		total = 0;
	
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			total += arr[i];
		}
		
		if(total % 4 != 0){
			cout << "no\n";
		}else{
			vector<bool> dp(1 << n);
			if(dfs(arr, dp, 0, total / 4)){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}
	}
	
	return 0;
}