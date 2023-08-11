#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        parent[y] = x;
    }
}

int bfs(vector<string>& lake){

    int r = lake.size();
    int c = lake[0].size();

    vector<int> parent(r * c);
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }

    vector<int> swan;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(r, vector<bool>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(lake[i][j] == 'L'){
                swan.push_back(i * c + j);
                lake[i][j] = '.';
            }
            if(lake[i][j] == '.'){
                bool check = false;
                for(int k = 0; k < 4; k++){
                    int next_r = i + dr[k];
                    int next_c = j + dc[k];
                    if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
                        continue;
                    }
                    if(lake[next_r][next_c] == '.'){
                        union_parent(parent, i * c + j, next_r * c + next_c);
                    }else if(lake[next_r][next_c] == 'X'){
                        check = true;
                    }
                }
                if(check){
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    int answer = 0;

    queue<pair<int, int>> q2;

    while(find_parent(parent, swan[0]) != find_parent(parent, swan[1])){

        answer++;

        int sz = q.size();

        for(int i = 0; i < sz; i++){
            auto now = q.front();
            q.pop();
            for(int j = 0; j < 4; j++){
                int next_r = now.first + dr[j];
                int next_c = now.second + dc[j];
                if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c or visited[next_r][next_c]){
                    continue;
                }
                if(lake[next_r][next_c] == 'X'){
                    lake[next_r][next_c] = '.';
                    visited[next_r][next_c] = true;
                    q.push(make_pair(next_r, next_c));
                    q2.push(make_pair(next_r, next_c));
                }
            }
        }

        while(!q2.empty()){
            auto now = q2.front();
            q2.pop();
            for(int i = 0; i < 4; i++){
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
                    continue;
                }
                if(lake[next_r][next_c] == '.'){
                    union_parent(parent, now.first * c + now.second, next_r * c + next_c);
                }
            }
        }

    }

    return answer;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<string> lake(r);
    for(int i = 0; i < r; i++){
        cin >> lake[i];
    }

    cout << bfs(lake);

    return 0;
}