#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {1, 0};
int dc[] = {0, 1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x == y){
        return;
    }
    sz[x] += sz[y];
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> parent(n * m + 1);
    vector<int> sz(n * m + 1);

    for(int i = 1; i <= n * m; i++){
        parent[i] = i;
    }

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> start;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x == 1){
                start.push_back(i * m + j);
            }
        }
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 2; k++){
                int next_r = i + dr[k];
                int next_c = j + dc[k];
                if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                    continue;
                }
                edges.push_back(make_pair(abs(arr[i][j] - arr[next_r][next_c]), make_pair(i * m + j, next_r * m + next_c)));
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<long long> result(start.size());
    vector<int> left(start.size());
    vector<int> right(start.size(), edges.size());

    vector<vector<int>> mids(edges.size() + 1);

    while(1){
    
        bool check = false;

        for(auto& it : mids){
            it.clear();
        }

        for(int i = 0; i < start.size(); i++){
            if(left[i] <= right[i]){
                check = true;
                mids[(left[i] + right[i]) / 2].push_back(i);
            }
        }

        if(!check){
            break;
        }

        for(int i = 0; i <= n * m; i++){
            parent[i] = i;
            sz[i] = 1;
        }

        for(int i = 0; i < edges.size(); i++){

            int c = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;

            union_parent(parent, sz, u, v);

            for(auto& j : mids[i]){
                if(sz[find_parent(parent, start[j])] >= t){
                    result[j] = c;
                    right[j] = i - 1;
                }else{
                    left[j] = i + 1;
                }
            }
        }


    }

    long long answer = 0;
    for(int i = 0; i < result.size(); i++){
        answer += result[i];
    }

    cout << answer;


    return 0;
}