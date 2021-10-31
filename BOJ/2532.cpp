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
		int num;
		cin >> num;
		cin >> arr[i].first >> arr[i].second;
		arr[i].second = -arr[i].second;
	}
	
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	
	vector<int> answer;
	answer.push_back(-1987654321);
	
	for(int i = 0; i < n; i++){
		if(answer.back() <= arr[i].second){
			answer.push_back(arr[i].second);
		}else{
			auto it = upper_bound(answer.begin(), answer.end(), arr[i].second);
			*it = arr[i].second;
		}
	}
	
	cout << answer.size() - 1;
	
	return 0;
}