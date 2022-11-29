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
	}
	
	sort(arr.begin(), arr.end());
	
	int answer = 987654321;
	for(int i = n - 1; i >= 0; i--){
		answer = min(answer, arr[i].first);
		answer -= arr[i].second;
	}
	
	cout << max(answer, -1);
	
	return 0;
}