#include <iostream>
#include <vector>
#include <algorithm>

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
	
	sort(arr.begin(), arr.end());
	
	long long answer = 0;
	long long sum = 0;
	long long min_size = arr[0].first;
	
	for(int i = 0; i < n; i++){
		sum += arr[i].second;
		answer = max(answer, sum - arr[i].first + min_size);
		if(i != n - 1){
			min_size = max(min_size, arr[i + 1].first - sum);
		}
	}
	
	cout << answer;
	
	return 0;
}