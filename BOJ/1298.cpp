#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& student, vector<int>& laptop, vector<bool>& visited, int idx){
	
	for(int i = 0; i < student[idx].size(); i++){
		
		int now = student[idx][i];
		
		if(visited[now]){
			continue;
		}
		
		visited[now] = true;
		
		if(laptop[now] == 0 or dfs(student, laptop, visited, laptop[now])){
			laptop[now] = idx;
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
	
	vector<vector<int>> student(n + 1);
	vector<int> laptop(n + 1);
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		student[a].push_back(b);
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		vector<bool> visited(n + 1, false);
		if(dfs(student, laptop, visited, i)){
			answer++;
		}
	}
		
	cout << answer;
	
	return 0;
}