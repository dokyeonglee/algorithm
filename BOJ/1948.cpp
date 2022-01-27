#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solve(vector<vector<pair<int, int>>>& adj, vector<int>& in_degree, int src, int dst){
	
	vector<int> result(adj.size());
	queue<pair<int, int>> q;
	q.push(make_pair(src, 0));
	
	while(!q.empty()){
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();
		
		for(int i = 0; i < adj[now].size(); i++){
			int next = adj[now][i].first;
			int next_cost = adj[now][i].second;
			result[next] = max(result[next], cost + next_cost);
			if(--in_degree[next] == 0){
				q.push(make_pair(next, result[next]));
			}
		}
	}
	return result;
}

int solve2(vector<vector<pair<int, int>>>& adj, vector<int>& time_result, int dst){
	
	vector<bool> visited(time_result.size());
	visited[dst] = true;
	
	queue<int> q;
	q.push(dst);
	
	int result = 0;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i = 0; i < adj[now].size(); i++){
			int prev = adj[now][i].first;
			int prev_cost = adj[now][i].second;
			if(time_result[now] - prev_cost == time_result[prev]){
				result++;
				if(!visited[prev]){
					visited[prev] = true;
					q.push(prev);
				}
			}
		}
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int m;
	cin >> m;
	
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<vector<pair<int, int>>> reverse_adj(n + 1);
	vector<int> in_degree(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
		reverse_adj[v].push_back(make_pair(u, c));
		in_degree[v]++;
	}
	
	int src, dst;
	cin >> src >> dst;
	
	vector<int> time_result = solve(adj, in_degree, src, dst);
	cout << time_result[dst] << "\n" << solve2(reverse_adj, time_result, dst);
	
	return 0;
}