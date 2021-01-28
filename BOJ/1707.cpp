#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool is_bipartite(vector<vector<int>>& graph, int v, vector<int>& colors, int color){
	
	queue<int> q;
	q.push(v);
	colors[v] = color;
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int next : graph[now]){
			if(colors[next] == 0){
				q.push(next);
				colors[next] = colors[now] ^ 3;
			}else if(colors[now] == colors[next]){
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k;
	cin >> k;
	
	for(int test_case = 1; test_case <= k; test_case++){
		
		int v, e;
		cin >> v >> e;
		
		vector<vector<int>> graph(v + 1);
		vector<int> colors(v + 1);
		
		for(int i = 0; i < e; i++){
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		bool answer = true;
		
		for(int i = 1; i <= v; i++){
			if(colors[i] == 0){
				if(!is_bipartite(graph, i, colors, 1)){
					answer = false;
					break;
				}
			}
		}
		
		if(answer){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
        
	}
	
	return 0;
}