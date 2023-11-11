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

    long long pair_cnt = 0;
    long long bridge_cnt = 0;

    for(int i = 1; i < n; i++){
        int x;
        cin >> x;
        long long sz1 = sz[find_parent(parent, x)];
        long long sz2 = sz[find_parent(parent, x + 1)];
        pair_cnt += sz1 * sz2;
        bridge_cnt += sz1 * sz2 * (sz1 + sz2) / 2;
        union_parent(parent, sz, x, x + 1);
        cout << pair_cnt << " " << bridge_cnt << "\n";
    }

    return 0;
}