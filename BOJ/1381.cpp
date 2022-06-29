#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
		arr[i].first *= -1;
	}
	
	sort(arr.begin(), arr.end());
	
	double answer = 1;
	for(int i = 0; i < k; i++){
		answer *= (100 - arr[i].second) / 100.0;
	}
	
	answer = (1 - answer) * 100;
	if(answer < 1e-3){
		cout << "GG";
	}else{
		cout << fixed;
		cout.precision(3);
		cout << answer;
	}
	return 0;
}