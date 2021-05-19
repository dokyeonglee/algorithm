#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(-x);
	}
	
	int answer = 0;
	
	while(pq.size() > 1){
		int x = pq.top();
		pq.pop();
		x += pq.top();
		pq.pop();
		pq.push(x);
		answer += -x;
	}
	
	cout << answer;
	
	return 0;
}