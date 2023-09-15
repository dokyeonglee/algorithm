
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

int solve(vector<vector<int>>& arr, vector<int>& parent, vector<int>& sz, int d, int n){

    

    int result = 0;

    for(int i = 0; i < n * n; i++){
        if(find_parent(parent, i) == i){
            result = max(result, sz[i]);
        }
    }

    return result;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 5, vector<int>(n + 5, 987654321));

    vector<int> parent(n * n + n + 5);
    vector<int> sz(n * n + n + 5);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = i * n + j;
            for(int k = 0; k < 2; k++){
                int y = (i + dr[k]) * n + (j + dc[k]);
                edges.push_back(make_pair(abs(arr[i][j] - arr[i + dr[k]][j + dc[k]]), make_pair(x, y)));
            }
        }
    }

    sort(edges.begin(), edges.end());

    int left = 0;
    int right = 1e6;

    int answer = 0;

    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
        sz[i] = 1;
    }

    for(int i = 0; i < edges.size(); i++){

        int c = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        int pu = find_parent(parent, u);
        int pv = find_parent(parent, v);

        if(pu != pv){
            union_parent(parent, sz, pu, pv);
            if(sz[pu] >= (n * n + 1) / 2){
                answer = c;
                break;
            }
        }

    }

    cout << answer;

    return 0;
}