#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int find_parent(vector<int>& parent, int x){
	if(parent[x] == x){
		return parent[x];
	}
	return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
	x = find_parent(parent, x);
	y = find_parent(parent, y);
	if(x > y){
		swap(x, y);
	}
	parent[y] = x;
}


int bfs(vector<vector<pair<int, int>>>& adj, int src, int dst){
	
	vector<bool> visited(adj.size() + 2, false);
	vector<int>  max_weight(adj.size() + 2, 987654321);
	
	visited[src] = true;
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(auto next : adj[now]){
			if(!visited[next.first]){
				visited[next.first] = true;
				q.push(next.first);
				max_weight[next.first] = min(max_weight[now], next.second);
				
			}
		}
	}
	
	if(max_weight[dst] == 987654321){
		return 0;
	}
	return max_weight[dst];
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<int> parent(n + 1);
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	
	int src, dst;
	cin >> src >> dst;
	
	int u, v, c;
	vector<tuple<int, int, int>> edges(m);
	vector<vector<pair<int, int>>> adj(n + 1);
	
	for(int i = 0; i < m; i++){
		cin >> u >> v >> c;		
		edges[i] = make_tuple(-c, u, v);
	}
	
	sort(edges.begin(), edges.end());
	
	for(auto edge: edges){
		tie(c, u, v) = edge;
		if(find_parent(parent, u) != find_parent(parent, v)){
			union_parent(parent, u, v);
			adj[u].push_back(make_pair(v, -c));
			adj[v].push_back(make_pair(u, -c));
		}
		
	}
	
	cout << bfs(adj, src, dst);
		
	return 0;
}