#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(vector<vector<int>>& direction, vector<vector<int>>& cost, vector<vector<bool>>& visited, vector<vector<bool>>& check, int r, int c){
    
    visited[r][c] = true;

    int temp_r = r + dr[direction[r][c]];
    int temp_c = c + dc[direction[r][c]];

    int result = 0;

    if(temp_r < 0 or temp_r >= direction.size() or temp_c < 0 or temp_c >= direction[0].size()){
        return 0;
    }

    if(!visited[temp_r][temp_c]){
        result = dfs(direction, cost, visited, check, temp_r, temp_c);
    }else if(!check[temp_r][temp_c]){
        int temp = cost[r][c];
        while(r != temp_r or c != temp_c){
            if(temp_r < 0 or temp_r >= direction.size() or temp_c < 0 or temp_c >= direction[0].size()){
                check[r][c] = true;
                return 0;
            }
            temp = min(temp, cost[temp_r][temp_c]);
            int k = direction[temp_r][temp_c];
            temp_r += dr[k];
            temp_c += dc[k];
        }
        result += temp;
    }

    check[r][c] = true;

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> direction(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            if(str[j] == 'U'){
                direction[i][j] = 0;
            }else if(str[j] == 'R'){
                direction[i][j] = 1;
            }else if(str[j] == 'D'){
                direction[i][j] = 2;
            }else{
                direction[i][j] = 3;
            }
        }
    }

    vector<vector<int>> cost(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cost[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<bool>> check(n, vector<bool>(m));

    int answer = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                int c = dfs(direction, cost, visited, check, i, j);
                answer += c;
            }
        }
    }

    cout << answer;

    return 0;
}