#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<pair<int, int>>>& tree, int u, int v){
	
	vector<bool> visited(tree.size(), false);
	visited[u] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(u, 0));
	
	while(!q.empty()){
		
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(now == v){
			return cnt;
		}
		
		for(auto next : tree[now]){
			if(!visited[next.first]){
				visited[next.first] = true;
				q.push(make_pair(next.first, cnt + next.second));
			}
		}
	}
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> tree(n + 1);
	for(int i = 0; i < n - 1; i++){
		int u, v, c;
		cin >> u >> v >> c;
		tree[u].push_back(make_pair(v, c));
		tree[v].push_back(make_pair(u, c));
	}
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		cout << bfs(tree, u, v) << "\n";
	}
	
	return 0;
}