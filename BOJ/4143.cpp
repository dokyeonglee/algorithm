#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string find_parent(unordered_map<string, string>& parent, string x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(unordered_map<string, string>& parent, unordered_map<string, int>& sz, string x, string y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    sz[x] += sz[y];
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        unordered_map<string, string> parent;
        unordered_map<string, int> sz;

        for(int i = 0; i < n; i++){
            string u, v;
            cin >> u >> v;
            if(parent.count(u) == 0){
                parent[u] = u;
                sz[u] = 1;
            }
            if(parent.count(v) == 0){
                parent[v] = v;
                sz[v] = 1;
            }
            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, sz, u, v);    
            }
            cout << sz[parent[u]] << "\n";
        }

    }

    return 0;
}