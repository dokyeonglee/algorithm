#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r;
	cin >> n >> m >> r;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 987654321));
	vector<int> item(n + 1);
	
	for(int i = 1; i <= n; i++){
		cin >> item[i];	
	}
	
	for(int i = 1; i <= n; i++){
		graph[i][i] = 0;	
	}
	
	for(int i = 0; i < r; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = min(graph[u][v], c);
		graph[v][u] = min(graph[v][u], c);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		int result = 0;
		for(int j = 1; j <= n; j++){
			if(graph[i][j] <= m){
				result += item[j];
			}
		}
		answer = max(answer, result);
	}
	
	cout << answer;
	
	return 0;
}