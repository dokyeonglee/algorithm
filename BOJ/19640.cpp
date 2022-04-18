#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
	vector<queue<pair<pair<int, int>, pair<int, int>>>> v(m);
	for(int i = 0; i < n; i++){
		int d, h;
		cin >> d >> h;
		v[i % m].push(make_pair(make_pair(d, h), make_pair(-i % m, i)));
	}
	
	for(int i = 0; i < m; i++){
		if(!v[i].empty()){
			pq.push(v[i].front());
			v[i].pop();
		}
	}
	
	int answer = 0;
	while(!pq.empty()){
		if(pq.top().second.second == k){
			break;
		}
		answer++;
		int idx = -pq.top().second.first;
		pq.pop();
		if(!v[idx].empty()){
			pq.push(v[idx].front());
			v[idx].pop();
		}
	}
	
	cout << answer;
	
	return 0;
}