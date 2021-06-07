#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int r, int c, bool blindness = false){
	
	int n = graph.size();
	int color = graph[r][c] | blindness;
	
	visited[r][c] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
				continue;
			}
			
			int next_color = graph[next_r][next_c] | blindness;
			
			if(!visited[next_r][next_c] and (color ^ next_color) == 0){
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
			
		}
		
	}
	
	return;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			if(str[j] == 'G'){
				graph[i][j] = 1;
			}else if(str[j] == 'B'){
				graph[i][j] = 2;
			}
		}
	}
	
	int answer = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				bfs(graph, visited, i, j);
				answer++;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		fill(visited[i].begin(), visited[i].end(), false);
	}
	
	cout << answer << " ";
	
	answer = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!visited[i][j]){
				bfs(graph, visited, i, j, true);
				answer++;
			}
		}
	}
	
	cout << answer;
	
	return 0;
}