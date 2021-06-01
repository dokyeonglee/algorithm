#include <iostream>
#include <vector>

using namespace std;

int solve(vector<bool>& arr, vector<vector<int>>& dp, int day, int coupon, int price){
	
	int n = arr.size() - 1;
	
	if(n < day){
		return price;
	}
	
	if(dp[day][coupon]){
		return dp[day][coupon] + price;
	}
	
	if(arr[day]){
		return solve(arr, dp, day + 1, coupon, price);
	}
	
	int result = 987654321;
	result = min(result, solve(arr, dp, day + 1, coupon, price + 10000));
	result = min(result, solve(arr, dp, day + 3, coupon + 1, price + 25000));
	result = min(result, solve(arr, dp, day + 5, coupon + 2, price + 37000));
	
	if(coupon >= 3){
		result = min(result, solve(arr, dp, day + 1, coupon - 3, price));
	}
	
	dp[day][coupon] = result - price;
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<bool> arr(n + 1);
	for(int i = 0; i < m; i++){
		int v;
		cin >> v;
		arr[v] = true;
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	cout << solve(arr, dp, 1, 0, 0);
	
	return 0;
}