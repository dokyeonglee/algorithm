#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double heron(int a, int b, int c){
	double s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

double solve(vector<int>& arr, vector<double>& dp, int bit, int s){
	
	if(s == arr.size()){
		return 0;
	}
	
	if(arr.size() - __builtin_popcount(bit) < 3){
		return 0;
	}
	
	double& ret = dp[bit];
	
	if(ret != -1){
		return ret;
	}
	
	ret = solve(arr, dp, bit, s + 1);
	
	if(bit & (1 << s)){
		return ret;
	}
	
	for(int i = s + 1; i < arr.size(); i++){
		if(bit & (1 << i)){
			continue;
		}
		for(int j = i + 1; arr[s] + arr[i] > arr[j] and j < arr.size(); j++){
			if(bit & (1 << j)){
				continue;
			}
			ret = max(ret, heron(arr[s], arr[i], arr[j]) + solve(arr, dp, bit | (1 << i) | (1 << j) | (1 << s), s + 1));
		}
	}
	
	return ret;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	
	vector<double> dp(1 << n, -1);
	
	cout << fixed;
	cout << setprecision(10);
	cout << solve(arr, dp, 0, 0);
	
	return 0;
}