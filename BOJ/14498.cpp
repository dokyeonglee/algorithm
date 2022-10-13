#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& d, int x){
	for(int p : adj[x]){
		if(visited[p]){
			continue;	
		}
		visited[p] = true;
		if(d[p] == -1 or dfs(adj, visited, d, d[p])){
			d[p] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<pair<int, int>> arr;
	vector<pair<int, int>> brr;
	
	for(int i = 0; i < k; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if(c == 0){
			arr.push_back(make_pair(a, b));
		}else{
			brr.push_back(make_pair(a, b));
		}
	}
	
	vector<vector<int>> adj(arr.size());
	
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < brr.size(); j++){
			if(arr[i].first == brr[j].first or arr[i].second == brr[j].second){
				adj[i].push_back(j);
			}
		}
	}
	
	vector<int> d(brr.size(), -1);
	int answer = 0;
	for(int i = 0; i < adj.size(); i++){
		vector<bool> visited(brr.size(), false);
		if(dfs(adj, visited, d, i)){
			answer++;
		}
	}
	
	cout << answer;
	
	return 0;
}