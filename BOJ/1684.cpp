#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
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
	
	vector<int> diff(n - 1);
	for(int i = 1; i < n; i++){
		diff[i - 1] = arr[i] - arr[i - 1];
	}
	
	int answer = diff[0];
	for(int i = 1; i < diff.size(); i++){
		answer = gcd(answer, diff[i]);
	}
	
	cout << answer;
	
	return 0;
}