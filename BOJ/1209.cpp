#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
	
	priority_queue<int> pq;
	
	long long answer = 0;
	
	for(int i = 0; i < n; i++){
		pq.push(arr[i]);
		if(arr[i] < pq.top()){
			answer += pq.top() - arr[i];
			pq.pop();
			pq.push(arr[i]);
		}
	}
	
	reverse(arr.begin(), arr.end());
	while(!pq.empty()){
		pq.pop();
	}
	
	long long answer2 = 0;
	
	for(int i = 0; i < n; i++){
		pq.push(arr[i]);
		if(arr[i] < pq.top()){
			answer2 += pq.top() - arr[i];
			pq.pop();
			pq.push(arr[i]);
		}
	}
	
	cout << min(answer, answer2);
	
	return 0;
}