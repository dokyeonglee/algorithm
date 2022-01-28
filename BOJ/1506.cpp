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

void scc(vector<vector<int>>& reverse_graph, vector<bool>& visited, vector<int>& cost, int& result, int now){
	visited[now] = true;
	result = min(result, cost[now]);
	for(int next : reverse_graph[now]){
		if(visited[next]){
			continue;
		}
		scc(reverse_graph, visited, cost, result, next);
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> cost(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}
	
	vector<vector<int>> graph(n + 1);
	vector<vector<int>> reverse_graph(n + 1);
	
	for(int i = 1; i <= n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < n; j++){
			if(str[j] == '1'){
				graph[i].push_back(j + 1);
				reverse_graph[j + 1].push_back(i);
			}
		}
	}
	
	stack<int> s;
	vector<bool> visited(n + 1);
	
	for(int i = 1; i <= n; i++){
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
		int result = 987654321;
		scc(reverse_graph, visited, cost, result, now);
		answer += result;
	}

	cout << answer;
	
	return 0;
}