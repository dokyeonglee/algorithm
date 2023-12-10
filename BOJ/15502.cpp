#include <iostream>
#include <vector>

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

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int x = 0; x < m; x++){
        int l, r, k;
        cin >> l >> r >> k;
        for(int i = l; i < l + k; i++){
            for(int j = i + k; j <= r; j += k){
                union_parent(parent, i, j);
            }
        }
    }

    int answer = 1;
    const int mod = 1e9 + 7;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            answer = 2 * answer % mod;
        }
    }

    cout << answer;

    return 0;
}