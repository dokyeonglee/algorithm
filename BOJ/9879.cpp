#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {0, 1};
int dc[] = {1, 0};

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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n * m);
    for(int i = 1; i < parent.size(); i++){
        parent[i] = i;
    }

    vector<vector<int>> arr(n, vector<int>(m));
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin >> arr[row][col];
        }
    }

    vector<int> sz(n * m);
    int cnt = 0;
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cin >> sz[row * m + col];
            cnt += sz[row * m + col];
        }
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            int u = row * m + col;
            for(int k = 0; k < 2; k++){
                int next_r = row + dr[k];
                int next_c = col + dc[k];
                if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                    continue;
                }
                int v = next_r * m + next_c;
                int c = abs(arr[row][col] - arr[next_r][next_c]);
                edges.emplace_back(c, make_pair(u, v));
            }
        }
    }

    sort(edges.begin(), edges.end());

    for(auto& e : edges){
        int c = e.first;
        int pu = find_parent(parent, e.second.first);
        int pv = find_parent(parent, e.second.second);
        if(pu != pv){
            if(sz[pu] + sz[pv] == cnt){
                cout << c;
                return 0;
            }
            union_parent(parent, sz, pu, pv);
        }
    }

    return 0;
}