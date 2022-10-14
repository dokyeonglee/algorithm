#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& d, int x, int t){
	visited[x] = t;
	for(int p : adj[x]){
		if(d[p] == -1 or (visited[d[p]] != t and dfs(adj, visited, d, d[p], t))){
			d[p] = x;
			return true;
		}
	}
	return false;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int h, v;
		cin >> h >> v;
		vector<vector<pair<char, int>>> board(2500, vector<pair<char, int>>(2500));
		for(int i = 0; i < h; i++){
			int x, y;
			cin >> x >> y;
			string str;
			cin >> str;
			for(int j = 0; j < str.size(); j++){
				board[y][x + j] = make_pair(str[j], i);
			}
		}
		vector<vector<int>> adj(h);
		for(int i = 0; i < v; i++){
			int x, y;
			cin >> x >> y;
			string str;
			cin >> str;
			for(int j = 0; j < str.size(); j++){
				if(board[y + j][x].first != 0 and board[y + j][x].first != str[j]){
					adj[board[y + j][x].second].push_back(i);
				}
			}
		}
		
		vector<int> d(v, -1);
		vector<int> visited(v, -1);

		int answer = h + v;
		for(int i = 0; i < h; i++){
			if(dfs(adj, visited, d, i, i)){
				answer--;
			}
		}
		
		cout << answer << "\n";
		
	}
	
	return 0;
}