#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int bfs(vector<string>& arr, pair<int, int>& a_src, pair<int, int>& b_src){

    vector<vector<vector<vector<bool>>>> visited(arr.size(), vector<vector<vector<bool>>>(arr[0].size(), vector<vector<bool>>(arr.size(), vector<bool>(arr[0].size()))));
    visited[a_src.first][a_src.second][b_src.first][b_src.second] = true;

    queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    q.push(make_pair(0, make_pair(a_src, b_src)));

    while(!q.empty()){

        int cnt = q.front().first;
        auto a = q.front().second.first;
        auto b = q.front().second.second;
        q.pop();

        if(a == b_src and b == a_src){
            return cnt;
        }

        for(int i = 0; i < 9; i++){
            pair<int, int> next_a = make_pair(a.first + dr[i], a.second + dc[i]);
            if(next_a.first < 0 or next_a.first >= arr.size() or next_a.second < 0 or next_a.second >= arr[0].size() or arr[next_a.first][next_a.second] == 'X'){
                continue;
            }
            for(int j = 0; j < 9; j++){
                pair<int, int> next_b = make_pair(b.first + dr[j], b.second + dc[j]);
                if(next_b.first < 0 or next_b.first >= arr.size() or next_b.second < 0 or next_b.second >= arr[0].size() or arr[next_b.first][next_b.second] == 'X'){
                    continue;
                }
                if(!visited[next_a.first][next_a.second][next_b.first][next_b.second] and !(next_b == a and next_a == b) and next_a != next_b){
                    visited[next_a.first][next_a.second][next_b.first][next_b.second] = true;
                    q.push(make_pair(cnt + 1, make_pair(next_a, next_b)));
                }
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    pair<int, int> a, b;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'A'){
                a = make_pair(i, j);
            }else if(arr[i][j] == 'B'){
                b = make_pair(i, j);
            }
        }
    }

    cout << bfs(arr, a, b);

    return 0;
}