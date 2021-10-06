#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<int>& people, vector<vector<int>>& graph, vector<bool>& visited, int now, int bit){
	
	visited[now] = true;
	
	int result = people[now];
	
	for(int next : graph[now]){
		if((bit & (1 << next)) and !visited[next]){
			result += dfs(people, graph, visited, next, bit);
		}
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> people(n);
	int sum = 0;
	
	for(int i = 0; i < n; i++){
		cin >> people[i];
		sum += people[i];
	}
	
	vector<vector<int>> graph(n + 1);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int v;
			cin >> v;
			graph[i].push_back(v - 1);
			graph[v - 1].push_back(i);
		}
	}
	
	int answer = 987654321;
	
	for(int i = 1; i < (1 << n) - 1; i++){
		
		vector<bool> visited(n + 1, false);
		int s1, s2;
		
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				s1 = dfs(people, graph, visited, j, i);
				break;
			}
		}
		for(int j = 0; j < n; j++){
			if(~i & (1 << j)){
				s2 = dfs(people, graph, visited, j, ~i);
				break;
			}
		}
		
		if(s1 + s2 == sum){
			answer = min(answer, abs(s1 - s2));
		}
	}
	
	if(answer == 987654321){
		cout << -1;
	}else{
		cout << answer;
	}
	
	return 0;
}