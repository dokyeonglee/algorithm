#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<long long>& sz, int x, int y){
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
    vector<long long> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    long long answer = n;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if(find_parent(parent, a) != find_parent(parent, b)){
            answer -= (sz[find_parent(parent, a)] - 1) * sz[find_parent(parent, a)] / 2;
            answer -= (sz[find_parent(parent, b)] - 1) * sz[find_parent(parent, b)] / 2;
            union_parent(parent, sz, a, b);
            answer += (sz[find_parent(parent, a)] - 1) * sz[find_parent(parent, a)] / 2;
        }
        cout << answer << "\n";
    }

    return 0;
}