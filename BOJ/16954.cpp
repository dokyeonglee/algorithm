#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool can_move(vector<string>& board, int r, int c, int cnt){
    
    cnt--;
    
    if(r >= cnt and board[r - cnt][c] == '#'){
    	return false;
    }
    
    if(r >= cnt + 1 and board[r - cnt - 1][c] == '#'){
        return false;
    }
    
    return true;
    
}

int bfs(vector<string>& board){
    
    vector<vector<vector<bool>>> visited(8, vector<vector<bool>>(8, vector<bool>(9, false)));
    visited[7][0][0] = true;
    
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(7, 0)));
    
    while(!q.empty()){
        
        int cnt = q.front().first;
        pair<int,int> now = q.front().second;
    	q.pop();
    	
        if((now.first == 0 and now.second == 7) or cnt >= 8){
            return 1;
        }
        
        for(int i = 0; i < sizeof(dr) / sizeof(int); i++){
            
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            
            if(next_r < 0 or next_r >= 8 or next_c < 0 or next_c >= 8){
                continue;
            }
            
            if(!visited[next_r][next_c][cnt + 1] and can_move(board, next_r, next_c, cnt + 1)){
                visited[next_r][next_c][cnt + 1] = true;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }
            
        }
        
    }
    
    return 0;
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> board(8);
    for(int i = 0; i < 8; i++){
        cin >> board[i];
    }
    
    cout << bfs(board);
    
    return 0;
}
