#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& arr, vector<int>& answer, int s){
	
	for(int u : arr[s]){
		answer[u] += answer[s];
		dfs(arr, answer, u);
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n + 1);
	
	for(int i = 1; i <= n; i++){
		int u;
		cin >> u;
		if(u != -1){
			arr[u].push_back(i);
		}
	}
	
	vector<int> answer(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, c;
		cin >> u >> c;
		answer[u] += c;
	}
	
	dfs(arr, answer, 1);
	
	for(int i = 1; i <= n; i++){
		cout << answer[i] << " ";
	}
	
	return 0;
}