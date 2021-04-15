#include <iostream>
#include <vector>

using namespace std;

int tsp(vector<vector<int>>& graph, vector<vector<int>>& cache, int now, int visited){
	
	int n = graph.size();
	
	if(visited == (1 << n) - 1){
		if(graph[now][0] != 0){
			return graph[now][0];
		}
		return 987654321;
	}
	
	int& result = cache[now][visited];
	if(result != -1){
		return result;
	}
	
	result = 987654321;
	
	for(int next = 0; next < n; next++){
		if(visited & (1 << next) or graph[now][next] == 0){
			continue;
		}
		int temp = graph[now][next] + tsp(graph, cache, next, visited | (1 << next));
		result = min(result, temp);
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> graph[i][j];
		}
	}
	
	vector<vector<int>> cache(n, vector<int>(1 << n, -1));
	
	cout << tsp(graph, cache, 0, 1);
	
	return 0;
	
}