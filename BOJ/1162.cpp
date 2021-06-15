#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, vector<vector<long long>>& distance){
	
	int k = distance[0].size() - 1;
	
	distance[1][0] = 0;
	
	priority_queue<tuple<long long, long long, long long>> pq;
	pq.push(make_tuple(0, 0, 1));
	
	long long dist, cnt, now;
	
	while(!pq.empty()){
		
		tie(dist, cnt, now) = pq.top();
		pq.pop();
		
		dist = -dist;
		
		if(distance[now][cnt] < dist){
			continue;
		}
		
		for(pair<int, int> e : graph[now]){
			
			long long next = e.first;
			long long cost = e.second + dist;
			
			if(cost < distance[next][cnt]){
				distance[next][cnt] = cost;
				pq.push(make_tuple(-cost, cnt, next));
			}
			
			if(cnt < k and dist < distance[next][cnt + 1]){
				distance[next][cnt + 1] = dist;
				pq.push(make_tuple(-dist, cnt + 1, next));
			}
			
		}
		
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	vector<vector<long long>> distance(n + 1, vector<long long>(k + 1, 1e18));
	
	dijkstra(graph, distance);
	
	long long answer = 1e18;
	
	for(int i = 0; i <= k; i++){
		answer = min(answer, distance[n][i]);
	}
	
	cout << answer;
	
	return 0;
}