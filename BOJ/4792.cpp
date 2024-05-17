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

int solve(vector<vector<pair<int, int>>>& edges, int n, int idx){

    int result = 0;

    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(auto& e : edges[idx]){
        if(find_parent(parent, e.first) != find_parent(parent, e.second)){
            union_parent(parent, e.first, e.second);
            result++;
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1){

        int n, m, k;
        cin >> n >> m >> k;

        if(n == 0 and m == 0 and k == 0){
            break;
        }

        vector<vector<pair<int, int>>> edges(2);

        for(int i = 0; i < m; i++){
            char color;
            int u, v;
            cin >> color >> u >> v;
            if(color == 'B'){
                edges[0].emplace_back(u, v);
            }else{
                edges[1].emplace_back(u, v);
            }
        }

        if(k <= solve(edges, n, 0) and k >= n - 1 - solve(edges, n, 1)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }

    }

    return 0;
}