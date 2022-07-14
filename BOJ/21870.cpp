#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}

long long solve(vector<int>& arr, int left, int right){
	int n = right - left + 1;
	if(n == 1){
		return arr[left];
	}
	int left_gcd = arr[left];
	for(int i = left + 1; i < left + n / 2; i++){
		left_gcd = gcd(left_gcd, arr[i]);
	}
	int right_gcd = arr[left + n / 2];
	for(int i = left + n / 2; i <= right; i++){
		right_gcd = gcd(right_gcd, arr[i]);
	}
	return max(left_gcd + solve(arr, left + n / 2, right), right_gcd + solve(arr, left, left + n / 2 - 1));
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
	
	cout << solve(arr, 0, n - 1);
	
	return 0;
}