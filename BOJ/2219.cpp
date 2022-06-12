#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 987654321));
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
		graph[v][u] = c;
	}
	
	for(int i = 1; i <= n;i++){
		graph[i][i] = 0;
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int answer = -1;
	int _min = 1e9;
	
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = 1; j <= n; j++){
			sum += graph[i][j];
		}
		if(sum < _min){
			_min = sum;
			answer = i;
		}
	}
	
	cout << answer;
	
	return 0;
}