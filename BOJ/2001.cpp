#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<pair<int, int>>>& graph, vector<int>& jewelry, int k){
	
	int result = 0;
	
	vector<vector<bool>> visited(graph.size(), vector<bool>(1 << k, false));
	visited[1][0] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));

	/*if(jewelry[1] != -1){
		visited[1][1 << jewelry[1]] = true;
		q.push(make_pair(1, 1 << jewelry[1]));
	}*/
	
	while(!q.empty()){
		
		int now = q.front().first;
		int bit = q.front().second;
		q.pop();
		
		if(now == 1){
			result = max(result, __builtin_popcount(bit));
		}
		
		if(jewelry[now] != -1 and !visited[now][bit | (1 << jewelry[now])]){
			visited[now][bit | (1 << jewelry[now])] = true;
			q.push(make_pair(now, bit | (1 << jewelry[now])));
		}
		
		for(pair<int, int> e : graph[now]){
		
			int next = e.first;
			int next_bit = bit;
			
			if(!visited[next][next_bit] and e.second >= __builtin_popcount(next_bit)){
				visited[next][next_bit] = true;
				q.push(make_pair(next, next_bit));
			}
			
		}
		
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> jewelry(n + 1, -1);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		jewelry[x] = i;
	}
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	cout << bfs(graph, jewelry, k);
	
	return 0;
}