#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].second >> arr[i].first;
		arr[i].first *= -1;
		arr[i].second *= -1;
	}
	
	sort(arr.begin(), arr.end());
	int answer = -arr[0].first + arr[0].second;
	
	for(int i = 1; i < n; i++){
		if(answer < -arr[i].first){
			answer += arr[i].second;
		}else{
			answer = -arr[i].first + arr[i].second;
		}
	}
	
	cout << answer;
	
	return 0;
}