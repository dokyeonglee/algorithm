#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){
	
	vector<int> result(graph.size(), 1);
	
	queue<int> q;
	
	for(int i = 1; i < graph.size(); i++){
		if(in_degree[i] == 0){
			q.push(i);	
		}
	}
	
	for(int i = 1; i < graph.size(); i++){
		
		int now = q.front();
		q.pop();
		
		for(int next : graph[now]){
			if(--in_degree[next] == 0){
				result[next] = result[now] + 1;
				q.push(next);
			}
		}
		
	}
	
	for(int i = 1; i < graph.size(); i++){
		cout << result[i] << " ";
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1);
	vector<int> in_degree(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		in_degree[v]++;
	}
	
	topology_sort(graph, in_degree);
	
	return 0;
}