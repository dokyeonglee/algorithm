#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    sz[x] += sz[y];
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, sz, u, v);
        }
    }

    vector<pair<int, int>> answer;
    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            answer.push_back(make_pair(sz[i], i));
        }
    }

    sort(answer.begin(), answer.end(), greater<>());

    if(answer.size() == 1){
        cout << 1 << " " << 1;
        return 0;
    }
    
    cout << answer[0].second << " " << answer[1].second;

    return 0;
}