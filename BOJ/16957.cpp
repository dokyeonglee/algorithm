#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    vector<int> parent(r * c);
    vector<int> sz(r * c, 1);

    for(int i = 1; i < r * c; i++){
        parent[i] = i;
    }

    vector<vector<int>> arr(r, vector<int>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int idx = -1;
            int v = 1e9;
            for(int k = 0; k < 8; k++){
                int next_r = i + dr[k];
                int next_c = j + dc[k];
                if(next_r < 0 or next_r >= r or next_c < 0 or next_c >= c){
                    continue;
                }
                if(arr[i][j] > arr[next_r][next_c] and arr[next_r][next_c] < v){
                    v = arr[next_r][next_c];
                    idx = k;
                }
            }
            if(idx == -1) continue;
            int next_r = i + dr[idx];
            int next_c = j + dc[idx];
            union_parent(parent, sz, next_r * c + next_c, i * c + j);
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int p = find_parent(parent, i * c + j);
            if(p == i * c + j){
                cout << sz[p] << " ";
            }else{
                cout << "0 ";
            }
        }
        cout << "\n";
    }

    return 0;
}