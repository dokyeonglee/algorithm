#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& arr, vector<int>& sum, vector<int>& dp, int bankrupted_bit){
	int& ret = dp[bankrupted_bit];
	if(ret != -1){
		return ret;
	}
	ret = 0;
	if(__builtin_popcount(bankrupted_bit) == arr.size() - 1){
		return ret |= ~bankrupted_bit & -~bankrupted_bit;
	}
	for(int i = 0; i < arr.size(); i++){
		if((bankrupted_bit & (1 << i)) == 0 and sum[i] > 0){
			for(int j = 0; j < arr.size(); j++){
				sum[j] -= arr[j][i];
			}
			ret |= solve(arr, sum, dp, bankrupted_bit | (1 << i));
			for(int j = 0; j < arr.size(); j++){
				sum[j] += arr[j][i];
			}
		}
	}
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(n));
		vector<int> sum(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> arr[i][j];
				sum[i] += arr[i][j];
			}
		}
		
		if(n == 1){
			cout << "1\n";
			continue;
		}
		
		vector<int> dp(1 << n, -1);
		int answer = solve(arr, sum, dp, 0);
		answer <<= 1;
		if(answer == 0){
			answer |= 1;
		}
		
		for(int i = 0; i <= n; i++){
			if(answer & (1 << i)){
				cout << i << " ";
			}
		}
		cout << "\n";
	}
	
	return 0;
}