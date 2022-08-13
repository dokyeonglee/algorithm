#include <iostream>
#include <vector>

using namespace std;

double distance_square(double x1, double y1, double x2, double y2){
	return (x2 - x1) *(x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& d, int x){
	for(int i = 0; i < graph[x].size(); i++){
		int p = graph[x][i];
		if(visited[p]){
			continue;
		}
		visited[p] = true;
		if(d[p] == -1 or dfs(graph, visited, d, d[p])){
			d[p] = x;
			return true;
		}
	}	
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	double s, v;
	cin >> n >> m >> s >> v;
	
	vector<pair<double, double>> mouse(n);
	for(int i = 0; i < n; i++){
		cin >> mouse[i].first >> mouse[i].second;
	}

	vector<vector<int>> graph(n);
	vector<int> d(m, -1);
	
	for(int i = 0; i < m; i++){
		double x, y;
		cin >> x >> y;
		for(int j = 0; j < n; j++){
			if(distance_square(mouse[j].first, mouse[j].second, x, y) <= v * v * s * s){
				graph[j].push_back(i);
			}
		}
	}
	
	
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		vector<bool> visited(m);
		if(dfs(graph, visited, d, i)){
			answer++;
		}
	}
	
	answer = n - answer;
	
	cout << answer;
	
	return 0;
}