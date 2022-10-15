#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool dfs(vector<set<int>>& adj, vector<int>& visited, vector<int>& d, int x, int t){
	for(int p : adj[x]){
		if(visited[p] == t){
			continue;
		}
		visited[p] = t;
		if(d[p] == -1 or dfs(adj, visited, d, d[p], t)){
			d[p] = x;
			return true;
		}
	}
	return false;
}

void bfs(vector<string>& _floor, vector<vector<int>>& floor, vector<vector<bool>>& visited, int r, int c, int room){
	int n = visited.size();
	int m = visited[0].size();
    visited[r][c] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		floor[now.first][now.second] = room;
		for(int i = 0; i < 4; i++){
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
			if(!visited[next_r][next_c] and _floor[next_r][next_c] == '.'){
                visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int test_case = 1; test_case <= t; test_case++){
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<vector<string>> _building(k + 2, vector<string>(n));
        vector<vector<vector<int>>> building(k + 2, vector<vector<int>>(n, vector<int>(m)));
		for(int i = 1; i <= k; i++){
			for(int r = 0; r < n; r++){
				cin >> _building[i][r];
			}
		}
		
		int room = 1;
		for(int i = 1; i <= k; i++){
			vector<vector<bool>> visited(n, vector<bool>(m));
			for(int r = 0; r < n; r++){
				for(int c = 0; c < m; c++){
					if(!visited[r][c] and _building[i][r][c] == '.'){
						bfs(_building[i], building[i], visited, r, c, room++);
					}
				}
			}
		}
        
        vector<set<int>> adj(room);
        for(int i = 1; i <= k; i += 2){
            for(int r = 0; r < n; r++){
                for(int c = 0; c < m; c++){
                    if(building[i][r][c] and building[i - 1][r][c]){
                        adj[building[i][r][c]].insert(building[i - 1][r][c]);
                    }
                    if(building[i][r][c] and building[i + 1][r][c]){
                        adj[building[i][r][c]].insert(building[i + 1][r][c]);
                    }
                }
            }
        }
		
		vector<int> d(n * m * k , -1);
		vector<int> visited(n * m * k, -1);
		int answer = room - 1;

		for(int i = 0; i < adj.size(); i++){
			if(dfs(adj, visited, d, i, i)){
				answer--;
			}
		}
		
		cout << "Case #" << test_case <<": ";
		cout << answer << "\n";
		
	}
	
	
	
	return 0;
}