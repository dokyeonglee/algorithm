#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int v, e;
	cin >> v >> e;
	
	const int INF = 987654321;
	
	vector<vector<int>> graph(v + 1, vector<int>(v + 1, INF));
	for(int i = 0; i < e; i ++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
	}
	
	for(int k = 1; k <= v; k++){
		for(int i = 1; i <= v; i++){
			for(int j = 1; j <= v; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int answer = INF;
	for(int i = 1; i <= v; i++){
		for(int j = 1; j <= v; j++){
			if(i != j){
				answer = min(answer, graph[i][j] + graph[j][i]);
			}
		}
	}
	
	if(answer == INF){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}