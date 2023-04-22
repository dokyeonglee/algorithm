#include <iostream>
#include <vector>
#include <algorithm>

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

    int c, h, k;
    cin >> c >> h >> k;

    c = find_parent(parent, c);
    h = find_parent(parent, h);

    vector<int> v;
    for(int i = 1; i <= n; i++){
        int p = find_parent(parent, i);
        if(p != c and p != h and p == i){
            v.push_back(sz[p]);
        }
    }

    sort(v.begin(), v.end(), greater<>());

    int answer = sz[c];
    for(int i = 0; i < min((int)v.size(), k); i++){
        answer += v[i];
    }

    cout << answer;


    return 0;
}