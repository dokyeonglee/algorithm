#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& graph, pair<int, int> s, pair<int, int> e){
	
	int n = graph.size();
	
	vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(4, 987654321)));
	
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for(int i = 0; i < 4; i++){
		q.push(make_pair(make_pair(0, i), s));	
	}
	
	int result = 987654321;
	
	while(!q.empty()){
		
		pair<int, int> info = q.front().first;
		pair<int, int> now = q.front().second;
		q.pop();
		
		int cnt = info.first;
		pair<int, int> next = make_pair(now.first + dr[info.second], now.second + dc[info.second]);
		
		if(visited[now.first][now.second][info.second] <= cnt){
			continue;	
		}
		
		visited[now.first][now.second][info.second] = cnt;
		
		if(next.first < 0 or next.first >= n or next.second < 0 or next.second >= n){
			continue;
		}
		
		if(graph[next.first][next.second] == '*'){
			continue;
		}
		
		if(next == e){
			result = min(result, cnt);
		}
		
		q.push(make_pair(info, next));
		
		if(graph[next.first][next.second] == '!'){
			info.first++;
			info.second = (info.second + 1) % 4;
			q.push(make_pair(info, next));
			info.second = (info.second + 2) % 4;
			q.push(make_pair(info, next));
		}
		
	}
	
	return result;
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<string> graph(n);
	vector<pair<int, int>> pos;
	
	for(int i = 0; i < n; i++){
		cin >> graph[i];
		for(int j = 0; j < graph[i].size(); j++){
			if(graph[i][j] == '#'){
				pos.push_back(make_pair(i, j));
			}
		}
	}
	
	cout << bfs(graph, pos[0], pos[1]);
	
	return 0;
}