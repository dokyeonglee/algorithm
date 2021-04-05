#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

const pair<int, int> src = make_pair(0, 0);
const pair<int, int> dst = make_pair(10000, 10000);

int distance_square(pair<int, int> a, pair<int, int> b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool bfs(vector<pair<int, int>>& pos, int fuel, int limit){

	queue<tuple<pair<int, int>, int>> q;
	vector<bool> visited(pos.size() + 1, false);
	
	q.push(make_tuple(src, 0));
	visited[0] = true;
	
	long long max_distance_square = (long long) fuel * fuel * 100;
	
	pair<int, int> now;
	int cnt;
	
	while(!q.empty()){
		
		tie(now, cnt) = q.front();
		q.pop();
		
		if(distance_square(now, dst) <= max_distance_square){
			return true;
		}
		
		for(int i = 0; i < pos.size(); i++){
			
			if(visited[i]){
				continue;
			}
			
			pair<int, int> next = pos[i];
			
			if(distance_square(now, next) <= max_distance_square and cnt <= limit){
				q.push(make_tuple(next, cnt + 1));
				visited[i] = true;
			}
		}
		
	}
	
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int, int>> pos(n);
	for(int i = 0; i < n; i++){
		cin >> pos[i].first >> pos[i].second;
	}
		
	int lo = 1;
	int hi = 1415;
	int answer = 0;
	
	while(lo <= hi){
		
		int mid = (lo + hi) / 2;
		
		if(bfs(pos, mid, k)){
			answer = mid;
			hi = mid - 1;
		}else{
			lo = mid + 1;
		}
		
	}
	
	cout << answer;
	
	return 0;
}