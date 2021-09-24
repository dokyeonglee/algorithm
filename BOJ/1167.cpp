#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

pair<int, int> bfs(vector<vector<pair<int, int>>>& tree, int s){
	
	vector<int> distance(tree.size(), 1e9);
	distance[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(auto next : tree[now]){
			
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
	
	int u, v, c;
	
	for(int i = 0; i < n; i++){
		
		cin >> u;
		
		while(1){
			
			cin >> v;
			
			if(v == -1){
				break;
			}
			
			cin >> c;
			
			tree[u].push_back(make_pair(v, c));
			tree[v].push_back(make_pair(u, c));
		}
	}
	
	
	pair<int, int> result = bfs(tree, 1);
	pair<int, int> answer = bfs(tree, result.first);
	
	cout << answer.second;
	
	return 0;
}