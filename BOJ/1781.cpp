#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<int> pq;
	vector<pair<int, int>> arr(n);
	
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n; i++){
		pq.push(-arr[i].second);
		if(pq.size() > arr[i].first){
			pq.pop();
		}
	}
	
	int answer = 0;
	while(!pq.empty()){
		answer -= pq.top();
		pq.pop();
	}
	
	cout << answer;
	
	return 0;
}