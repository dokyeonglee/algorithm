#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int i = 0; i < n; i++){
		int s, e;
		cin >> s >> e;
		pq.push(make_pair(s, e));
	}
	
	priority_queue<int, vector<int>, greater<int>> answer;
	while(!pq.empty()){
		int s = pq.top().first;
		int e = pq.top().second;
		pq.pop();
		if(!answer.empty() and s >= answer.top()){
			answer.pop();
		}
		answer.push(e);
	}
	
	cout << answer.size();
	
	return 0;

}