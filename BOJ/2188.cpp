#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& arr, vector<int>& brr, vector<bool>& visited, int idx){
	
	for(int i = 0; i < arr[idx].size(); i++){
		
		if(visited[arr[idx][i]]){
			continue;
		}
		
		visited[arr[idx][i]] = true;
		
		if(brr[arr[idx][i]] == 0 or dfs(arr, brr, visited, brr[arr[idx][i]])){
			brr[arr[idx][i]] = idx;
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
	
	vector<vector<int>> arr(n + 1);
	vector<int> brr(m + 1);
	
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		for(int j = 0; j < x; j++){
			int v;
			cin >> v;
			arr[i].push_back(v);
		}
	}
	
	int answer = 0;
	
	for(int i = 1; i <= n; i++){
		
		vector<bool> visited(m + 1, false);
		
		if(dfs(arr, brr, visited, i)){
			answer++;		
		}
	}
	
	cout << answer;
	
	return 0;
}