#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<long long> distance(n + 1, 1e18);
	vector<vector<pair<int, int>>> graph(n + 1);
	
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
	}
	
	bool minus_cycle = false;
	
	distance[1] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= n; j++){
			for(pair<int, int> e : graph[j]){
				int next = e.first;
				int dist = e.second;
				if(distance[j] != 1e18 and distance[next] > distance[j] + dist){
					distance[next] = distance[j] + dist;
					if(i == n - 1){
						minus_cycle = true;
						break;
					}
				}
			}
		}
	}
	
	if(minus_cycle){
		cout << -1 << endl;
	}else{
		for(int i = 2; i <= n; i++){
			if(distance[i] == 1e18){
				cout << -1 << endl;
			}else{
				cout << distance[i] << endl;
			}
		}
	}
	
	return 0;
}