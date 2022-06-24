#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d;
	cin >> n >> d;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr.begin(), arr.end());
	
	int left = 0;
	int right = 0;
	long long answer = 0;
	long long sum = 0;
	while(left <= right and right < n){
		if(arr[right].first - arr[left].first < d){
			sum += arr[right++].second;
		}else{
			sum -= arr[left++].second;
		}
		answer = max(answer, sum);
	}
	
	cout << answer;
	
	return 0;
}