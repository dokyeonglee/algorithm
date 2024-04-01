#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void destroy_mineral(vector<string>& arr, int x, int& direction){

    int r = arr.size();
    int c = arr[0].size();

    if(direction){
        for(int i = 0; i < c; i++){
            if(arr[r  - x][i] == 'x'){
                arr[r - x][i] = '.';
                break;
            }
        }
        direction = 0;
    }else{
        for(int i = c - 1; i >= 0; i--){
            if(arr[r  - x][i] == 'x'){
                arr[r - x][i] = '.';
                break;
            }
        }
        direction = 1;
    }

}

void bfs(vector<string>& arr, vector<vector<bool>>& visited, int src_row, int src_col){

    int r = arr.size();
    int c = arr[0].size();

    visited[src_row][src_col] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(src_row, src_col));

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] == 'x'){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

}

vector<pair<int, int>> get_floating_mineral(vector<string>& arr, vector<vector<bool>>& visited){

    int r = arr.size();
    int c = arr[0].size();

    vector<pair<int, int>> floating_mineral;

    for(int i = 0; i < c; i++){
        if(!visited[r - 1][i] and arr[r - 1][i] == 'x'){
            bfs(arr, visited, r - 1, i);
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visited[i][j] and arr[i][j] == 'x'){
                floating_mineral.emplace_back(i, j);
            }
        }
    }

    return floating_mineral;

}

int get_drop_amount(vector<string>& arr, vector<vector<bool>>& visited, vector<pair<int, int>>& floating_mineral){

    int drop_amount = 1e9;

    int r = arr.size();

    for(auto& mineral : floating_mineral){
        int cnt = 0;
        for(int j = mineral.first + 1; j < r; j++){
            if(arr[j][mineral.second] == '.'){
                cnt++;
            }else if(visited[j][mineral.second]){
                break;
            }
        }
        drop_amount = min(drop_amount, cnt);
    }

    if(drop_amount == 1e9){
        drop_amount = -1;
    }

    return drop_amount;

}

void drop_mineral(vector<string>& arr, vector<vector<bool>>& visited, int drop_amount){

    int r = arr.size();
    int c= arr[0].size();

    for(int i = r - 1; i >= 0; i --){
        for(int j = 0; j < c; j++){
            if(arr[i][j] == 'x' and !visited[i][j]){
                arr[i + drop_amount][j] = 'x';
                arr[i][j] = '.';
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> arr(r);
    for(int i = 0; i < r; i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;
    
    int direction = 1;

    while(q--){

        int x;
        cin >> x;

        destroy_mineral(arr, x, direction);

        vector<vector<bool>> visited(r, vector<bool>(c));

        vector<pair<int, int>> floating_mineral = get_floating_mineral(arr, visited);
        
        int drop_amount = get_drop_amount(arr, visited, floating_mineral);

        if(drop_amount != -1){
            drop_mineral(arr, visited, drop_amount);
        }

    }

    for(int i = 0; i < r; i++){
        cout << arr[i] << "\n";
    }

    return 0;
}