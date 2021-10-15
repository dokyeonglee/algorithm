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

	vector<pair<int, int>> lecture;
	for(int i = 0; i < n; i++){
		int l, s, e;
		cin >> l >> s >> e;
		lecture.push_back(make_pair(s, e));
	}
	
	sort(lecture.begin(), lecture.end());
	
	priority_queue<pair<int, int>> pq;
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		if(pq.size() > 0){
			if(-pq.top().first > lecture[i].first){
				answer++;
			}else{
				pq.pop();
			}
		}else{
			answer++;
		}
		pq.push(make_pair(-lecture[i].second, -lecture[i].first));
	}
	
	cout << answer;
	return 0;
}