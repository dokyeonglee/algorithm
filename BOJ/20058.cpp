#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void rotate(vector<vector<int>>& arr, int r, int c, int l){
    vector<vector<int>> temp(l, vector<int>(l));
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            temp[i][j] = arr[r + l - 1 - j][c + i];
        }
    }
    for(int i = r; i < r + l; i++){
        for(int j = c; j < c + l; j++){
            arr[i][j] = temp[i - r][j - c];
        }
    } 
}

void rotate(vector<vector<int>>& arr, int l){
    if(l == 1) return;
    for(int i = 0; i < arr.size(); i += l){
        for(int j = 0; j < arr.size(); j += l){
            rotate(arr, i, j, l);
        }
    }
}

void melt(vector<vector<int>>& arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[i][j] == 0){
                continue;
            }
            int cnt = 4;
            for(int k = 0; k < 4; k++){
                int next_r = i + dr[k];
                int next_c = j + dc[k];
                if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr.size() or arr[next_r][next_c] == 0){
                    cnt--;
                }
            }
            if(cnt < 3){
                arr[i][j] = -arr[i][j];
            }
        }
    }
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(arr[i][j] < 0){
                arr[i][j] = -arr[i][j] - 1;
            }
        }
    }
}

int bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int r, int c){

    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    int cnt = 0;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        cnt++;

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr.size()){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] != 0){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    return cnt;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(1 << n, vector<int>(1 << n));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int l;
        cin >> l;
        rotate(arr, 1 << l);
        melt(arr);
    }

    int answer = 0;

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            answer += arr[i][j];
        }
    }

    cout << answer << "\n";

    answer = 0;
    vector<vector<bool>> visited(arr.size(), vector<bool>(arr.size()));
    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j < arr.size(); j++){
            if(!visited[i][j] and arr[i][j] != 0){
                answer = max(answer, bfs(arr, visited, i, j));
            }
        }
    }

    cout << answer;
    
    return 0;
}