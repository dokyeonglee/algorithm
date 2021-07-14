#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& board, int key){
	
	int h = board.size();
	int w = board[0].size();
	
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	
	int result = 0;
	
	vector<vector<pair<int, int>>> door(26);
	
	while(!q.empty()){
		
		pair<int, int> now = q.front();
		q.pop();
		
		if(board[now.first][now.second] == '$'){
			result++;
		}
		
		for(int i = 0; i < 4; i++){
			
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			
			if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
				continue;
			}
			
			char symbol = board[next_r][next_c];
			
			if(visited[next_r][next_c] or symbol == '*'){
				continue;
			}
			
			if(symbol >= 'A' and symbol <= 'Z'){
				if((key & (1 << (symbol - 'A'))) == 0){
					door[symbol - 'A'].push_back(make_pair(next_r, next_c));
					continue;
				}
			}
			
			if(symbol >= 'a' and symbol <= 'z'){
				key |= 1 << (symbol - 'a');
				for(pair<int, int> d : door[symbol - 'a']){
					q.push(d);
				}
			}
			
			visited[next_r][next_c] = true;
			q.push(make_pair(next_r, next_c));
			
		}
	}
	
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		
		int h, w;
		cin >> h >> w;
		
		vector<string> board(h + 2, string(w + 2, '.'));
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				cin >> board[i][j];
			}
		}
		
		string _key;
		cin >> _key;
		
		int key = 0;
		if(_key[0] != '0'){
			for(int i = 0; i < _key.size(); i++){
				key |= 1 << (_key[i] - 'A');
			}
		}
		
		cout << bfs(board, key) << "\n";
			
	}
	
	return 0;
}