#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

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
	
	vector<int> sum;
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			sum.push_back(arr[i] + arr[j]);
		}
	}
	
	map<int, int> sub;
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			sub[arr[j] - arr[i]] = max(sub[arr[j] - arr[i]], arr[j]);		
		}
	}
	
	int answer = 0;
	for(int i = 0; i < sum.size(); i++){
		answer = max(answer, sub[sum[i]]);
	}
	
	cout << answer;
	
	return 0;
}