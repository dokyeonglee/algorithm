#include <iostream>
#include <vector>
#include <map>


using namespace std;

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
	cin >> n >> m;
	
	map<string, int> member;
	for(int i = 1; i <= m; i++){
		string str;
		cin >> str;
		member[str] = i;
	}
	
	vector<vector<int>> graph(n + 1);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			string str;
			cin >> str;
			graph[i].push_back(member[str]);
		}
	}
	
	vector<int> d(m + 1, -1);
	
	int answer = 0;
	for(int i = 1; i <= n; i++){
		vector<bool> visited(m + 1, false);
		if(dfs(graph, visited, d, i)){
			answer++;
		}
	}

	if(answer == n){
		cout << "YES";
	}else{
		cout << "NO\n" << answer;
	}
	
	return 0;
}