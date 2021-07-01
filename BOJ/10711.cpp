#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(vector<vector<int>>& sand){
    
    int h = sand.size();
    int w = sand[0].size();
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(sand[i][j] == 0){
                q.push(make_pair(i, j));
            }
        }
    }

    int result = 0;
    
    while(1){
       
        int q_size = q.size();
        
        for(int i = 0; i < q_size; i++){
            
            pair<int, int> now = q.front();
            q.pop();
            
            sand[now.first][now.second] = 0;
            int cnt = 0;
                
            for(int k = 0; k < 8; k++){
                    
                int next_r = now.first + dr[k];
                int next_c = now.second + dc[k];
                    
                if(next_r < 0 or next_r >= h or next_c < 0 or next_c >= w){
                    continue;
                }
                
                sand[next_r][next_c]--;
                
                if(sand[next_r][next_c] == 0){
                    q.push(make_pair(next_r, next_c));
                }
                    
            }    
        }
        
        if(q.empty()){
        	break;
        }
        
        result++;
    }
    
    return result;
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    
    vector<vector<int>> sand(h, vector<int>(w, 0));

    for(int i = 0; i < h; i++){
        
        string str;
        cin >> str;
        
        for(int j = 0; j < w; j++){
            if(str[j] != '.'){
                sand[i][j] = str[j] - '0';
            }
        }
    }
    
    cout << bfs(sand);
    
    return 0;
}