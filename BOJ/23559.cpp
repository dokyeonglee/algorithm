#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<long long, long long> a, pair<long long, long long> b){
	return a.first - a.second > b.first - b.second;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n, x;
	cin >> n >> x;
	
	
	vector<pair<long long, long long>> arr(n);
	long long answer = 0;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), compare);
	
	for(int i = 0; i < n; i++){
		if(arr[i].first > arr[i].second and x - 5000 >= (n - i - 1) * 1000){
			answer += arr[i].first;
			x -= 5000;
		}else{
			answer += arr[i].second;
			x -= 1000;
		}
	}
	
	cout << answer;
	
	return 0;
}