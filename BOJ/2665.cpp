#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0 ,-1};

int bfs(vector<string>& graph){
	
	int n = graph.size();
	vector<vector<int>> distance(n, vector<int>(n, 987654321));
	distance[0][0] = 0;
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			if(distance[next_r][next_c] > distance[now.first][now.second]){
				distance[next_r][next_c] = distance[now.first][now.second] + '1' - graph[next_r][next_c];	
				q.push(make_pair(next_r, next_c));
			}
			
			
		}
		
	}
	
	return distance[n - 1][n - 1];
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<string> graph(n);
	for(int i = 0; i < n; i++){
		cin >> graph[i];
	}
	
	cout << bfs(graph);
	
	return 0;
}