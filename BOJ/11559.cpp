#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr, vector<vector<bool>>& visited, int r, int c, char color){

    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    vector<pair<int, int>> v;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        v.push_back(now);

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= 12 or next_c < 0 or next_c >= 6){
                continue;
            }

            if(!visited[next_r][next_c] and arr[next_r][next_c] == color){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }

        }
    }

    if(v.size() < 4){
        return false;
    }

    for(int i = 0; i < v.size(); i++){
        arr[v[i].first][v[i].second] = '.';
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> arr(12);
    for(int i = 0; i < 12; i++){
        cin >> arr[i];
    }
	
	int answer = 0;
	
    while(1){

        bool check = false;

        vector<vector<bool>> visited(12, vector<bool>(6));

        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 6; j++){
                if(!visited[i][j] and arr[i][j] != '.'){
                    check |= bfs(arr, visited, i, j, arr[i][j]);
                }
            }
        }

        for(int k = 0; k < 6; k++){
            for(int i = 11; i >= 0; i--){
                if(arr[i][k] == '.'){
                    for(int j = i - 1; j >= 0; j--){
                        if(arr[j][k] != '.'){
                            arr[i][k] = arr[j][k];
                            arr[j][k] = '.';
                            break;
                        }                 
                    }
                }
            }
        }

        if(!check){
            break;
        }else{
        	answer++;
        }
    }
    
    cout << answer;

    return 0;
}