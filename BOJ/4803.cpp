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

    int t = 1;

    while(1){

        int n, m;
        cin >> n >> m;

        if(n == 0 and m == 0){
            break;
        }

        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        vector<bool> is_tree(n + 1, true);

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            if(find_parent(parent, u) != find_parent(parent, v)){
                is_tree[find_parent(parent, u)] = is_tree[find_parent(parent, u)] & is_tree[find_parent(parent, v)];
                union_parent(parent, u, v);
            }else{
                is_tree[find_parent(parent, u)] = false;
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(find_parent(parent, i) == i){
                cnt += is_tree[i];
            }
        }
        
        cout << "Case " << t++ << ": ";

        if(cnt == 0){
            cout << "No trees.\n";
        }else if(cnt == 1){
            cout << "There is one tree.\n";
        }else{
            cout << "A forest of " << cnt << " trees.\n";
        }

    }

    return 0;
}