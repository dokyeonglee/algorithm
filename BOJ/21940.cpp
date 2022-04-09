#include <iostream>
#include <vector>

using namespace std;

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
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	
	int k;
	cin >> k;
	
	vector<int> arr(k);
	for(int i = 0; i < k; i++){
		cin >> arr[i];
	}
	
	int d = 987654321;
	vector<int> answer;
	for(int i = 1; i <= n; i++){
		int dist = -1;
		for(int j = 0; j < k; j++){
			dist = max(dist, graph[arr[j]][i] + graph[i][arr[j]]);
		}
		if(dist < 987654321){
			if(dist < d){
				d = dist;
				answer.clear();
				answer.push_back(i);
			}else if(dist == d){
				answer.push_back(i);	
			}
		}
	}
	
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}