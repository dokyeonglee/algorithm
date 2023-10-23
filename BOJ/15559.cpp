#include <iostream>
#include <vector>

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
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n * m);
    for(int i = 1; i < n * m; i++){
        parent[i] = i;
    }

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char d;
            cin >> d;
            if(d == 'E'){
                arr[i][j] = 1;
            }else if(d == 'S'){
                arr[i][j] = 2;
            }else if(d == 'W'){
                arr[i][j] = 3;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int next_r = i + dr[arr[i][j]];
            int next_c = j + dc[arr[i][j]];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            union_parent(parent, i * m + j, next_r * m + next_c);
        }
    }

    int answer = 0;
    for(int i = 0; i < n * m; i++){
        if(find_parent(parent, i) == i){
            answer++;
        }
    }

    cout << answer;

    return 0;
}