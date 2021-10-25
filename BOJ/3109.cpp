#include <iostream>
#include <vector>
 
using namespace std;
 
int dr[] = {-1, 0, 1};
int dc[] = {1, 1, 1};
 
int dfs(vector<string>& arr, vector<vector<bool>>& visited, int r, int c){
 
	int R = arr.size();
	int C = arr[0].size();
 
	visited[r][c] = true;
 
	if(c == C - 1){
		return 1;
	}
 
	for(int i = 0; i < 3; i++){
 
		int next_r = r + dr[i];
		int next_c = c + dc[i];
 
		if(next_r < 0 or next_r >= R or next_c < 0 or next_c >= C){
			continue;
		}
 
		if(!visited[next_r][next_c] and arr[next_r][next_c] == '.'){
			if(dfs(arr, visited, next_r, next_c) == 1){
				return 1;
			}
		}
 
	}
 
	return 0;
 
}
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int r, c;
	cin >> r >> c;
 
	vector<string> arr(r);
	for(int i = 0; i < r; i++){
		cin >> arr[i];
	}
 
	vector<vector<bool>> visited(r, vector<bool>(c, false));
 
	int answer = 0;
	for(int i = 0; i < r; i++){
		answer += dfs(arr, visited, i, 0);
	}
 
	cout << answer;
 
	return 0;
 
}