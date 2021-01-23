#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> bfs(vector<vector<pair<int, int>>>& tree, int s){
	
	vector<int> distance(tree.size(), 1e9);
	
	queue<int> q;
	distance[s] = 0;
	q.push(s);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(pair<int, int> next : tree[now]){
			
			int v = next.first;
			int w = next.second;
			
			if(distance[v] < 1e9){
				continue;
			}
			
			distance[v] = distance[now] + w;
			q.push(v);
		}
	}
	
	int idx = max_element(distance.begin() + 1, distance.end()) - distance.begin();
	
	return make_pair(idx, distance[idx]);
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<pair<int, int>>> tree(n + 1);
	
	for(int i = 1; i < n; i++){
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back(make_pair(v, w));
		tree[v].push_back(make_pair(u, w));
	}
	
	pair<int, int> u = bfs(tree, 1);
	pair<int, int> v = bfs(tree, u.first);
	
	cout << v.second << endl;
	
	return 0;
}