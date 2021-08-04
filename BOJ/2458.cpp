#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));
	
	for(int i = 1; i <= n; i++){
		graph[i][i] = 1;
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(graph[i][k] == 1 and graph[k][j] == 1){
					graph[i][j] = 1;
				}
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			cnt += (graph[i][j] == 0 and graph[j][i] == 0);
		}
		answer += (cnt == 0);
	}
	
	cout << answer;
	
	return 0;
}