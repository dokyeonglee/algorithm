#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<long long, long long>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	double answer = 0;
	for(int i = 0; i < n; i++){
		answer += (arr[i].first + arr[(i + 1) % n].first) * (arr[i].second - arr[(i + 1) % n].second);
	}
	
	cout << fixed;
	cout.precision(1);
	cout << round(abs(answer) / 2 * 10) / 10;
	
	return 0;
}