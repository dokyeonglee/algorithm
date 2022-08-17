#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
		if(arr[i].first < arr[i].second){
			swap(arr[i].first, arr[i].second);
		}
	}
	
	sort(arr.begin(), arr.end());
	
	int d;
	cin >> d;
	
	int answer = 0;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < n; i++){
		int right = arr[i].first;
		int left = arr[i].second;
		if(right - left <= d){
			pq.push(-left);
		}else{
			continue;
		}
		while(!pq.empty() and right + pq.top() > d){
			pq.pop();
		}
		answer = max(answer, (int)pq.size());
	}
	
	cout << answer;
	
	
	
	return 0;
}