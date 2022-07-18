#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	priority_queue<pair<int, int>> pq;
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pq.push(make_pair(x, i));
	}
	
	vector<vector<int>> graph(n, vector<int>(n));
	
	while(!pq.empty()){
		auto p = pq.top();
		pq.pop();
		if(p.first > pq.size()){
			cout << -1;
			return 0;
		}
		int u = p.second;
		vector<pair<int, int>> temp;
		for(int i = 0; i < p.first; i++){
			int v = pq.top().second;
			if(graph[u][v]){
				cout << -1;
				return 0;
			}
			graph[u][v] = 1;
			graph[v][u] = 1;
			temp.push_back(pq.top());
			pq.pop();
		}
		for(int i = 0; i < temp.size(); i++){
			temp[i].first--;
			pq.push(temp[i]);
		}
		
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
		
	return 0;
}