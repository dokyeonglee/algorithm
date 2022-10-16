#include <iostream>
#include <algorithm>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj){
	
	vector<int> distance(adj.size(), 1e18);
	distance[0] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 0));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(auto e : adj[now]){
			int next = e.first;
			int cost = e.second + dist;
			if(distance[next] > cost){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
			}
		}
	}
	
	return distance;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long m;
	cin >> m;
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	int _max = *max_element(arr.begin(), arr.end());
	
	vector<vector<pair<int, int>>> adj(_max);
	
	for(int i = 0; i < _max; i++){
		for(int j = 0; j < n; j++){
			if(i + arr[j] < _max){
				adj[i].push_back(make_pair(i + arr[j], 1));
			}else{
				adj[i].push_back(make_pair((i + arr[j]) % _max, 0));
			}
		}	
	}
	
	auto distance = dijkstra(adj);
	
	long long answer = m / _max + distance[m % _max];
	
	cout << answer;
	
	
	return 0;
}