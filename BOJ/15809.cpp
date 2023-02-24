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
    if(sz[x] < sz[y]){
        swap(x, y);
    }
    parent[y] = x;
    sz[x] += sz[y];
    sz[y] = 0;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1);
    
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        cin >> sz[i];
    }

    for(int i = 0; i < m; i++){

        int o, p, q;
        cin >> o >> p >> q;

        if(o == 1){
            union_parent(parent, sz, p, q);            
        }else{
            int u = find_parent(parent, p);
            int v = find_parent(parent, q);
            if(sz[u] > sz[v]){
                sz[u] -= sz[v];
                sz[v] = 0;
                union_parent(parent, sz, u, v);
            }else if(sz[u] < sz[v]){
                sz[v] -= sz[u];
                sz[u] = 0;
                union_parent(parent, sz, u, v);
            }else{
                sz[u] = 0;
                sz[v] = 0;
            }
        }

    }

    vector<int> answer;
    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i and sz[i]){
            answer.push_back(sz[i]);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << " ";
    }

    return 0;
}