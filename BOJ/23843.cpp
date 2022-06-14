#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end(), greater<int>());
	
	
	priority_queue<int> pq;
	int sz = min(n, m);
	while(pq.size() < sz){
		pq.push(-arr[pq.size()]);
	}
	
	for(int i = pq.size(); i < n; i++){
		int temp = -pq.top() + arr[i];
		pq.pop();
		pq.push(-temp);
	}
	
	int answer = 0;
	while(!pq.empty()){
		answer = max(answer, -pq.top());
		pq.pop();
	}
	
	cout << answer;
	
	return 0;
}