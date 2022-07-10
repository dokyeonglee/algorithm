#include <iostream>
#include <queue>

using namespace std;

struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return min(100 - a.first, a.second) < min(100 - b.first, b.second);
	}	
};

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<pair<int, int>> arr(m);
	for(int i = 0; i < m; i++){
		cin >> arr[i].first;
	}
	for(int i = 0; i < m; i++){
		cin >> arr[i].second;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	for(auto p : arr){
		pq.push(p);
	}
	
	int answer = 0;
	for(int i = 0; i < 24 * n and !pq.empty(); i++){
		auto p = pq.top();
		pq.pop();
		int score = min(100, p.first + p.second);
		if(score < 100){
			pq.push(make_pair(score, p.second));
		}else{
			answer += 100;
		}
	}
	
	while(!pq.empty()){
		answer += pq.top().first;
		pq.pop();
	}
	
	cout << answer;
	
	return 0;
}