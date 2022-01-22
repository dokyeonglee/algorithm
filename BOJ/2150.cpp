#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, stack<int>& s, int now){
	visited[now] = true;
	for(int next : graph[now]){
		if(visited[next]){
			continue;
		}
		dfs(graph, visited, s, next);
	}
	s.push(now);
}

void scc(vector<vector<int>>& reverse_graph, vector<bool>& visited, vector<int>& result, int now){
	visited[now] = true;
	result.push_back(now);
	for(int next : reverse_graph[now]){
		if(visited[next]){
			continue;
		}
		scc(reverse_graph, visited, result, next);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e;
	cin >> v >> e;
	
	vector<vector<int>> graph(v + 1);
	vector<vector<int>> reverse_graph(v + 1);
	
	for(int i = 0; i < e; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		reverse_graph[v].push_back(u);
	}
	
	stack<int> s;
	vector<bool> visited(v + 1);
	vector<vector<int>> answer;
	
	for(int i = 1; i <= v; i++){
		if(visited[i]){
			continue;
		}
		dfs(graph, visited, s, i);	
	}
	
	fill(visited.begin(), visited.end(), false);
	
	while(!s.empty()){
		int now = s.top();
		s.pop();
		if(visited[now]){
			continue;
		}
		vector<int> result;
		scc(reverse_graph, visited, result, now);
		answer.push_back(result);
	}

	for(int i = 0; i < answer.size(); i++){
		sort(answer[i].begin(), answer[i].end());
	}
	sort(answer.begin(), answer.end());
	
	cout << answer.size() << "\n";
	
	for(int i = 0; i < answer.size(); i++){
		for(int j = 0; j < answer[i].size(); j++){
			cout << answer[i][j] << " ";
		}
		cout << "-1\n";
	}
	
	return 0;
}