#include <iostream>
#include <vector>

using namespace std;

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

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, int>> edges(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> edges[i].first >> edges[i].second;
    }

    string color;
    cin >> color;

    vector<int> arr;

    for(int i = 0; i < n - 1; i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        if(color[u] == 'R' and color[v] == 'R'){
            union_parent(parent, sz, u, v);
        }else if(color[u] == 'B' and color[v] == 'R'){
            arr.push_back(v);
        }else if(color[u] == 'R' and color[v] == 'B'){
            arr.push_back(u);
        }
    }

    long long answer = 0;

    for(int i = 0; i < arr.size(); i++){
        answer += sz[find_parent(parent, arr[i])];
    }

    cout << answer;

    return 0;
}