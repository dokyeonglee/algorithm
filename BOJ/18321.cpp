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

    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> pos[i];
    }

    vector<pair<int, pair<int, int>>> edges(m);
    for(auto& e : edges){
        cin >> e.second.first >> e.second.second >> e.first;
    }

    sort(edges.begin(), edges.end(), greater<>());

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int answer = -1;

    int idx = 1;

    for(auto& e : edges){
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        while(idx <= n and find_parent(parent, idx) == find_parent(parent, pos[idx])){
            idx++;
        }
        if(idx > n){
            break;
        }
        if(find_parent(parent, u) != find_parent(parent, v)){
            answer = w;
            union_parent(parent, u, v);
        }
    }

    cout << answer;

    return 0;
}