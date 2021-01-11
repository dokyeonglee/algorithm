#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> jewelry(n);
	vector<int> bag(k);
	
	for(int i = 0; i < n; i++){
		cin >> jewelry[i].first >> jewelry[i].second;
	}
	
	for(int i = 0; i < k; i++){
		cin >> bag[i];
	}
	
	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());
	
	priority_queue<int> pq;
	
	long long answer = 0;
	int pos = 0;
	for(int i = 0; i < k; i++){
		while(pos < n and jewelry[pos].first <= bag[i]){
			pq.push(jewelry[pos].second);
			pos++;
		}
		if(!pq.empty()){
			answer += pq.top();
			pq.pop();
		}
	}
	
	cout << answer << endl;
	
	return 0;
}