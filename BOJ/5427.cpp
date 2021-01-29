#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


int escape(vector<vector<char>>& graph, pair<int, int> start, vector<pair<int, int>>& fire_pos){
	
	int h = graph.size();
	int w = graph[0].size();
	vector<vector<bool>> visited(h, vector<bool>(w));
	
	queue<pair<int, int>> q;
	queue<pair<int, int>> fire_q;
	
	for(pair<int, int> pos : fire_pos){
		fire_q.push(pos);
	}
	
	int result = 0;
	
	q.push(start);
	visited[start.first][start.second] = true;
	
	while(!q.empty()){
		
		int fire_q_size = fire_q.size();
		
		for(int i = 0; i < fire_q_size; i++){
			
			pair<int, int> now = fire_q.front();
			fire_q.pop();
			
			for(int j = 0; j < 4; j++){
				int next_r = now.first + dr[j];
				int next_c = now.second + dc[j];
				
				if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
					continue;
				}else if(graph[next_r][next_c] == '.'){
					graph[next_r][next_c] = '*';
					fire_q.push(make_pair(next_r, next_c));
				}	
			}
			
		}
		
		int q_size = q.size();
		
		for(int i = 0; i < q_size; i++){
			
			pair<int, int> now = q.front();
			q.pop();
			
			for(int j = 0; j < 4; j++){
				
				int next_r = now.first + dr[j];
				int next_c = now.second + dc[j];
				
				if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
					return result + 1;
				}else if(!visited[next_r][next_c] and graph[next_r][next_c] == '.'){
					visited[next_r][next_c] = true;
					q.push(make_pair(next_r, next_c));
				}	
			}
			
		}
		
		result++;
	}
	
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int test_case = 1; test_case <= t; test_case++){
		
		int w, h;
		cin >> w >> h;
		
		vector<vector<char>> graph(h, vector<char>(w));
		vector<pair<int, int>> fire_pos;
		
		pair<int, int> start;
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> graph[i][j];
				if(graph[i][j] == '*'){
					fire_pos.push_back(make_pair(i, j));
				}else if(graph[i][j] == '@'){
					start = make_pair(i, j);
					graph[i][j] = '.';
				}
			}
		}
		
		int escape_time = escape(graph, start, fire_pos);
		
		if(escape_time == -1){
			cout << "IMPOSSIBLE\n";
		}else{
			cout << escape_time << '\n';
		}
	}
	
	return 0;
}