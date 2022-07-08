#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<string, int>> arr(2 * n);
	for(int i = 0; i < n; i++){
		string s, e;
		cin >> s >> e;
		arr[2 * i] = make_pair(s, 1);
		arr[2 * i + 1] = make_pair(e, -1);
	}
	
	sort(arr.begin(), arr.end());
	
	int answer = 0;
	int sum = 0;
	
	for(auto p : arr){
		sum += p.second;
		answer = max(answer, sum);
	}
	
	cout << answer;
	
	return 0;
}