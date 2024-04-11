#include <iostream>
#include <queue>

using namespace std;

bool visited[21][21][101][101];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

pair<int, int> get_next(pair<int, int>& now, char dir){

    pair<int, int> next = now;

    if(dir == 'U'){
        next.first += dr[0];
        next.second += dc[0];
    }else if(dir == 'R'){
        next.first += dr[1];
        next.second += dc[1];
    }else if(dir == 'D'){
        next.first += dr[2];
        next.second += dc[2];
    }else if(dir == 'L'){
        next.first += dr[3];
        next.second += dc[3];
    }

    return next;

}

int bfs(vector<string>& arr, pair<int, int>& src, pair<int, int>& dst, string& dalgu, string& phoenix){

    int n = arr.size();
    
    visited[src.first][src.second][0][0] = true;
    
    queue<pair<pair<int , int>, pair<int, int>>> q;
    q.emplace(src, make_pair(0, 0));
    
    while(!q.empty()){

        auto now = q.front().first;
        auto idx = q.front().second;
        q.pop();

        if(now == dst){
            return idx.first + idx.second;
        }

        if(idx.first < dalgu.size()){

            auto next = get_next(now, dalgu[idx.first]);
            if(next.first < 0 or next.first >= n or next.second < 0 or next.second >= n or arr[next.first][next.second] == '#'){
                next = now;
            }

            if(!visited[next.first][next.second][idx.first + 1][idx.second]){

                visited[next.first][next.second][idx.first + 1][idx.second] = true;
                q.emplace(next, make_pair(idx.first + 1, idx.second));

            }
        }

        if(idx.second < phoenix.size()){
            
            auto next = get_next(now, phoenix[idx.second]);
            if(next.first < 0 or next.first >= n or next.second < 0 or next.second >= n or arr[next.first][next.second] == '#'){
                next = now;
            }

            if(!visited[next.first][next.second][idx.first][idx.second + 1]){

                visited[next.first][next.second][idx.first][idx.second + 1] = true;
                q.emplace(next, make_pair(idx.first, idx.second + 1));

            }
        }

    }
    
    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    pair<int, int> src;
    pair<int, int> dst;
    
    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 'S'){
                src = make_pair(i, j);
            }else if(arr[i][j] == 'E'){
                dst = make_pair(i, j);
            }
        }
    }
    
    string dalgu, phoenix;
    cin >> dalgu >> phoenix;

    cout << bfs(arr, src, dst, dalgu, phoenix);
    
    return 0;
    
}