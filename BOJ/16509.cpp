#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int bfs(pair<int, int>& elephant, pair<int, int>& king){
	
	vector<vector<bool>> visited(10, vector<bool>(9, false));
	visited[elephant.first][elephant.second];
	
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, elephant));
	
	while(!q.empty()){
		
		int cnt = q.front().first;
		auto now = q.front().second;
		q.pop();
		
		if(now == king){
			return cnt;
		}
		
        for(int k = 0; k < 2; k++){
            for(int i = 0; i < 8; i += 2){
                
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];

                if(next_r < 0 or next_r >= 10 or next_c < 0 or next_c >= 9 or (next_r == king.first and next_c == king.second)){
                    continue;
                }
                
                bool check = true;

                for(int j = 0; j < 2; j++){

                    next_r += dr[(i + 7 + 2 * k) % 8];
                    next_c += dc[(i + 7 + 2 * k) % 8];

                    if(next_r < 0 or next_r >= 10 or next_c < 0 or next_c >= 9 or (j == 0 and next_r == king.first and next_c == king.second)){
                        check = false;
                        break;
                    }
                }

                if(check and !visited[next_r][next_c]){
                    visited[next_r][next_c] = true;
                    q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
                }

            }

        }
	}
    
	return -1;
}

int main() {
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	pair<int, int> king;
	pair<int, int> elephant;
	
	cin >> elephant.first >> elephant.second;
	cin >> king.first >> king.second;
	
	cout << bfs(elephant, king);
	
	return 0;
}