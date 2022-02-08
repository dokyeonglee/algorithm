#include <iostream>
#include <vector>
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

void scc(vector<vector<int>>& graph, vector<bool>& visited, int now){
	visited[now] = true;
	for(int next : graph[now]){
		if(visited[next]){
			continue;
		}
		scc(graph, visited, next);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
	
		int v, e;
		cin >> v >> e;
		
		vector<vector<int>> graph(v + 1);
		vector<vector<int>> reverse_graph(v + 1);
		
		for(int i = 0; i < e; i++){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
		}
		
		stack<int> s;
		vector<bool> visited(v + 1);
		
		for(int i = 1; i <= v; i++){
			if(visited[i]){
				continue;
			}
			dfs(graph, visited, s, i);	
		}
		
		fill(visited.begin(), visited.end(), false);
		
		int answer = 0;
		
		while(!s.empty()){
			int now = s.top();
			s.pop();
			if(visited[now]){
				continue;
			}
			scc(graph, visited, now);
			answer++;
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}