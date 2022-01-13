#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> d(1001);
vector<bool> visited(1001);

bool dfs(vector<vector<int>>& arr, int x){
	for(int i = 0; i < arr[x].size(); i++){
		int t = arr[x][i];
		if(visited[t]){
			continue;
		}
		visited[t] = true;
		if(d[t] == 0 or dfs(arr, d[t])){
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin>> n >> m;
	
	vector<vector<int>> arr(n + 1);
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		arr[i].resize(x);
		for(int j = 0; j < x; j++){
			cin >> arr[i][j];
		}
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		fill(visited.begin(), visited.end(), false);
		if(dfs(arr, i)){
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}