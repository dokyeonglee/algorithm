#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topology_sort(vector<vector<int>>& graph, vector<int>& in_degree){
	
	vector<int> result;
	
	queue<int> q;
	
	for(int i = 1; i < in_degree.size(); i++){
		if(in_degree[i] == 0){
			q.push(i);
			result.push_back(i);
		}
	}
	
	for(int i = 1; i < graph.size(); i++){
		
		if(q.empty()){
			return {0};
		}
		
		int now = q.front();
		q.pop();
		
		for(int next : graph[now]){
			if(--in_degree[next] == 0){
				q.push(next);
				result.push_back(next);
			}	
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	vector<int> in_degree(N + 1);
	vector<vector<int>> graph(N + 1);
	
	for(int i = 0; i < M; i++){
		int n;
		cin >> n;
		
		int from;
		cin >> from;
		
		for(int j = 1; j < n; j++){
			int to;
			cin >> to;
			graph[from].push_back(to);
			in_degree[to]++;
			from = to;
		}
	}
	
	vector<int> answer = topology_sort(graph, in_degree);
	for(int i = 0; i < answer.size(); i++){
		cout << answer[i] << '\n';
	}
	
	return 0;
}