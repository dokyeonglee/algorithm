#include <iostream>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using pii_pii = pair<pii, pii>;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& board, pii& src, pii& dst1, pii& dst2){
	
	bool visited[51][51][5][4];
	visited[src.first][src.second][4][0] = true;
	
	queue<pair<pii_pii, int>> q;
	q.push(make_pair(make_pair(make_pair(-1, 0), src), 0));
	
	while(!q.empty()){

		int dir = q.front().first.first.first;
		int cnt = q.front().first.first.second;
		auto now = q.front().first.second;
		int bit = q.front().second;
		q.pop();
		
		if(bit == 3){
			return cnt;
		}

		for(int i = 0; i < 4; i++){
			int next_r = now.first + dr[i];
			int next_c = now.second + dc[i];
			auto next = make_pair(next_r, next_c);
			int next_bit = bit | (next == dst1) | (2 * (next == dst2));
			if(next_r < 0 or next_r >= board.size() or next_c < 0 or next_c >= board[0].size() or dir == i){
				continue;
			}
			if(!visited[next_r][next_c][i][next_bit] and board[next_r][next_c] != '#'){
				visited[next_r][next_c][i][next_bit] = true;
				q.push(make_pair(make_pair(make_pair(i, cnt + 1), next), next_bit));
			}
		}
	}
	
	return -1;
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int R, C;
	cin >> R >> C;
	
	vector<string> board(R);
	
	pii src, dst[2];
	int cnt = 0;
	
	for(int i = 0; i < R; i++){
		cin >> board[i];
		for(int j = 0; j < C; j++){
			if(board[i][j] == 'S'){
				src.first = i;
				src.second = j;
			}else if(board[i][j] == 'C'){
				dst[cnt].first = i;
				dst[cnt++].second = j;
			}
		}
	}
	cout << bfs(board, src, dst[0], dst[1]);
	
	return 0;
}