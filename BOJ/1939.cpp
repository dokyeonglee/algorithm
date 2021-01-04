#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1987654321;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> weight(n + 1, -1);
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(c, v));
		graph[v].push_back(make_pair(c, u));
	}
	
	int src, dst;
	cin >> src >> dst;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(MAX, src));
	weight[src] = MAX;
	
	while(!pq.empty()){
		int w = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if(weight[now] > w){
			continue;
		}
		
		for(pair<int, int> e : graph[now]){
			int cost = min(w, e.first);
			if(cost > weight[e.second]){
				weight[e.second] = cost;
				pq.push(make_pair(cost, e.second));
			}
		}
	}
	
	cout << weight[dst] << endl;
	
	return 0;
}