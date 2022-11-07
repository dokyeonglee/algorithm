#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	double answer = 0;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<pair<long long, long long>> arr(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i].first >> arr[i].second;
		}
		
		double result = 0;
		for(int i = 0; i < n; i++){
			result += (arr[i].first + arr[(i + 1) % n].first) * (arr[i].second - arr[(i + 1) % n].second);
		}
		
		answer += abs(result) / 2;
	}
	
	cout << (long long)floor(answer);
	
	return 0;
}