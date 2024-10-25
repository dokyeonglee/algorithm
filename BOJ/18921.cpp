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

    vector<pair<int, pair<int, int>>> edges(n - 1);

    for(auto& edge : edges){
        cin >> edge.second.first >> edge.second.second >> edge.first;
    }

    sort(edges.rbegin(), edges.rend());

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    long long answer = 0;

    for(auto& edge : edges){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, sz, u, v);
            answer = max(answer, 1ll * (sz[find_parent(parent, u)] - 1) * c);
        }
    }

    cout << answer;

    return 0;
}