#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> arr;
	int prev, now;
	
	cin >> prev;
	++prev;
	
	for(int i = 0; i < n - 1; i++){
		cin >> now;
		if(now > prev){
			arr.push_back(now - prev);
		}
		prev = now + 1;
	}
	
	sort(arr.begin(), arr.end());
	
	long long answer = n;
	
	for(int i = 0; i < (int)arr.size() - k + 1; i++){
		answer += arr[i];
	}
	
	cout << answer;
	
	return 0;
}