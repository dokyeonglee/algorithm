#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& graph, queue<pair<int, pair<int, int>>>& q){
	
	int n = graph.size();
	int m = graph[0].size();
	
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}

			if(graph[next_r][next_c] > 2){
				return cnt + 1;
			}
			
			if(!visited[next_r][next_c] and graph[next_r][next_c] == 0){
				visited[next_r][next_c] = true;
				q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
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
	
	vector<vector<int>> graph(n, vector<int>(m));
	queue<pair<int, pair<int, int>>> q;
	
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		for(int j = 0; j < str.size(); j++){
			graph[i][j] = str[j] - '0';
			if(graph[i][j] == 2){
				q.push(make_pair(0, make_pair(i, j)));
			}
		}
	}
	
	int answer = bfs(graph, q);
	if(answer == -1){
		cout << "NIE";
	}else{
		cout << "TAK\n";
		cout << answer;
	}
	
	return 0;
}