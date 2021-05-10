#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dijkstra(vector<vector<int>>& graph){
	
	int n = graph.size();
	
	vector<vector<int>> distance(n, vector<int>(n, 987654321));
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[0][0] = true;
	
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(-graph[0][0], make_pair(0, 0)));
	
	while(!pq.empty()){
		
		int cost = -pq.top().first;
		pair<int, int> now = pq.top().second;
		pq.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			int next_cost = cost + graph[next_r][next_c];
			
			if(visited[next_r][next_c] == false and distance[next_r][next_c] > next_cost){
				visited[next_r][next_c] = true;
				distance[next_r][next_c] = next_cost;
				pq.push(make_pair(-next_cost, make_pair(next_r, next_c)));
			}
			
		}
		
	}
	
	return distance[n - 1][n - 1];
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int test_case = 1;
	
	while(1){
		
		int answer = 0;
		int n;
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		vector<vector<int>> graph(n, vector<int>(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		
		cout << "Problem " << test_case << ": " << dijkstra(graph) << "\n";
		
		test_case++;
		
	}
	
	return 0;
}