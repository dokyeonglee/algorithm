#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(vector<vector<int>>& graph, vector<bool>& visited, int src){
	
	visited[src] = true;
	
	queue<int> q;
	q.push(src);
	
	vector<int> result;
	result.push_back(src);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int i = 1; i < graph.size(); i++){
			if(!visited[i] and graph[now][i] < 987654321){
				result.push_back(i);
				visited[i] = true;
				q.push(i);
			}
		}
		
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 987654321));
	
	for(int i = 1; i <= n; i++){
		graph[i][i] = 0;
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	vector<bool> visited(n + 1, false);
	vector<vector<int>> committee;
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			committee.push_back(bfs(graph, visited, i));
		}
	}
	
	vector<int> answer;
	
	for(int k = 0; k < committee.size(); k++){
		
		int idx = 0;
		int dist = 987654321;
		
		for(int i = 0; i < committee[k].size(); i++){
			
			int max_dist = 0;
			int represent = committee[k][i];
			
			for(int j = 0; j < committee[k].size(); j++){
				int member = committee[k][j];
				max_dist = max(max_dist, graph[represent][member]);
			}
			
			if(max_dist < dist){
				idx = represent;
				dist = max_dist;
			}
			
		}
		
		answer.push_back(idx);
		
	}
	
	sort(answer.begin(), answer.end());
	
	cout << committee.size() << "\n";
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << "\n";
	}
	return 0;
}