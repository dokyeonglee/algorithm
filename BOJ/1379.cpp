#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<pair<int, int>, int>> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i].second >> arr[i].first.first >> arr[i].first.second;
	}
	
	sort(arr.begin(), arr.end());
	
	priority_queue<pair<pair<int, int>, int>> pq;
	
	vector<int> answer(n + 1);
	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		if(pq.size() > 0){
			if(-pq.top().first.first > arr[i].first.first){
				cnt++;
				answer[arr[i].second] = cnt;
			}else{
				answer[arr[i].second] = pq.top().second;
				pq.pop();
			}
		}else{
			cnt++;
			answer[arr[i].second] = cnt;
		}
		pq.push(make_pair(make_pair(-arr[i].first.second, -arr[i].first.first), answer[arr[i].second]));
	}
	
	cout << cnt << "\n";
	for(int i = 1; i <= n; i++){
		cout << answer[i] << "\n";
	}
	
	return 0;
}