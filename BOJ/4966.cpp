#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d, int now){
	for(int next : graph[now]){
		if(visited[next]){
			continue;
		}
		visited[next] = true;
		if(d[next] == -1 or dfs(graph, visited, d, d[next])){
			d[next] = now;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0){
			break;
		}
		vector<int> blue(n);
		vector<int> red(m);
		for(int i = 0; i < n; i++){
			cin >> blue[i];
		}
		for(int i = 0; i < m; i++){
			cin >> red[i];
		}
		vector<vector<int>> graph(n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(gcd(blue[i], red[j]) > 1){
					graph[i].push_back(j);	
				}
			}
		}
		vector<int> d(m, -1);
		int answer = 0;
		for(int i = 0; i < n; i++){
			vector<bool> visited(m);
			if(dfs(graph, visited, d, i)){
				answer++;
			}
		}
		cout << answer << "\n";
	}
	
	
	
	return 0;
}