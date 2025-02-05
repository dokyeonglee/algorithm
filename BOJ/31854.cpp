#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

vector<vector<int>> topology_sort(vector<vector<int>>& in_degree){

    int n = in_degree.size();

    queue<pair<int, int>> q;

    vector<vector<int>> result(n, vector<int>(n));

    int x = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(in_degree[i][j] == 0){
                result[i][j] = ++x;
                q.emplace(i, j);
            }
        }
    }

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
                continue;
            }
            if(--in_degree[next_r][next_c] == 0){
                result[next_r][next_c] = ++x;
                q.emplace(next_r, next_c);
            }
        }

    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> in_degree(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 1; j < n; j++){
            char c;
            cin >> c;
            if(c == '<'){
                in_degree[i][j]++;
            }else{
                in_degree[i][j - 1]++;
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            if(c == '<'){
                in_degree[i][j]++;
            }else{
                in_degree[i - 1][j]++;
            }
        }
    }

    auto answer = topology_sort(in_degree);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;

}