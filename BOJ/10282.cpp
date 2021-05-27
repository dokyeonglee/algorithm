#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int src){
	
	vector<int> distance(graph.size(), 987654321);
	distance[src] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(pair<int, int> e : graph[now]){
			
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
	
	int T;
	cin >> T;
	
	while(T--){
		
		int n, d, src;
		cin >> n >> d >> src;
		
		vector<vector<pair<int, int>>> graph(n + 1);
		
		for(int i = 0; i < d; i++){
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back(make_pair(a, s));
		}
		
		vector<int> distance = dijkstra(graph, src);
		
		int cnt = 0;
		int answer = -1;
		
		for(int i = 1; i <= n; i++){
			if(distance[i] != 987654321){
				cnt++;
				answer = max(answer, distance[i]);
			}
		}
		
		cout << cnt << " " << answer << "\n";
		
	}
	
	return 0;
}