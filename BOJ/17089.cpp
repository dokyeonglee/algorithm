#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graph(n + 1, vector<int>(n + 1));
	vector<int> cnt(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u][v] = 1;
		graph[v][u] = 1;
		cnt[u]++;
		cnt[v]++;
	}
	
	int answer = 987654321;
	
	for(int i = 1; i <= n; i++){
		if(cnt[i] < 2){
			continue;
		}
		for(int j = i + 1; j <= n; j++){
			if(cnt[j] < 2 or graph[i][j] == 0){
				continue;
			}
			for(int k = j + 1; k <= n; k++){
				if(cnt[k] < 2 or graph[i][k] == 0 or graph[j][k] == 0){
					continue;
				}
				answer = min(answer, cnt[i] + cnt[j] + cnt[k] - 6);
			}
		}
	}
	
	if(answer == 987654321){
		answer = -1;
	}
	
	cout << answer;
	
	return 0;
}