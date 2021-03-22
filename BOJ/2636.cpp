#include <bits/stdc++.h>
 
using namespace std;
 
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
 
void bfs(vector<vector<int>>& cheese){
 
	int n = cheese.size();
	int m = cheese[0].size();
	
	vector<vector<bool>> visited(n, vector<bool>(m , false));
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while(!q.empty()){
 
		pair<int, int> now = q.front();
		q.pop();
 
		for(int i = 0; i < 4; i++){
 
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
 
			if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
				continue;
			}
 
			if(!visited[next_r][next_c] and cheese[next_r][next_c] != 1){
				q.push(make_pair(next_r, next_c));
				visited[next_r][next_c] = true;
				cheese[next_r][next_c] = 2;
			}
		}
	}
}
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	vector<vector<int>> cheese(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> cheese[i][j];	
		}
	}
 	
 	bool melt_check = false;
 	int answer = 0;
 	int cheese_size = 0;
 	
	while(!melt_check){
		
		bfs(cheese);
		
		cheese_size = 0;
		melt_check = false;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(cheese[i][j] == 1){
					
					cheese_size++;
					
					for(int k = 0; k < 4; k++){
 
						int next_r = i + dr[k];
						int next_c = j + dc[k];
 
						if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
							continue;
						}
						
						if(cheese[next_r][next_c] == 2){
							melt_check = true;
							cheese[i][j] = 3;
						}
					}		
					
				}
			}
		}	
		
		if(melt_check){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(cheese[i][j] == 3){
						cheese[i][j] = 2;
					}
				}
			}
		}
		
		answer++;
		
		melt_check = true;
		
		for(int i = 0; i < n and melt_check; i++){
			for(int j = 0; j < m and melt_check; j++){
				if(cheese[i][j] == 1){
					melt_check = false;
				}
			}
		}

	}
	
	cout << answer << endl;
	cout << cheese_size << endl;

	return 0;
}