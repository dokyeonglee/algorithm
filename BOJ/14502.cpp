#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int result = 0;

void bfs(vector<vector<int>>& lab){

	int n = lab.size();
	int m = lab[0].size();

	queue<pair<int, int>> q;
	vector<vector<int>> infected_lab(lab);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(infected_lab[i][j] == 2){
				q.push(make_pair(i, j));	
			}
		}
	}

	while(!q.empty()){
		
		int curr_row = q.front().first;
		int curr_col = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			
			int next_row = curr_row + dr[i];
			int next_col = curr_col + dc[i];
			
			if(next_row < 0 or next_row >= n or next_col < 0 or next_col >= m){
				continue;	
			}
			
			if(infected_lab[next_row][next_col] == 0){
				infected_lab[next_row][next_col] = 2;
				q.push(make_pair(next_row, next_col));
			}
		}
	}
	
	int answer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(infected_lab[i][j] == 0){
				answer++;
			}
		}
	}
	
	result = max(result, answer);
}

void put_up_wall(vector<vector<int>>& lab, int cnt){
	
	if(cnt == 3){
		bfs(lab);
		return;
	}else{
		for(int i = 0; i < lab.size(); i++){
			for(int j = 0; j < lab[i].size(); j++){
				if(lab[i][j] == 0){
					lab[i][j] = 1;
					put_up_wall(lab, cnt + 1);
					lab[i][j] = 0;
				}
			}
		}	
	}
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> lab(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> lab[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(lab[i][j] == 0){
				
				vector<vector<int>> temp(lab);
				
				temp[i][j] = 1;
				put_up_wall(temp, 1);
				temp[i][j] = 0;
				
			}
		}
	}
	
	cout << result << endl;
	
	return 0;
}