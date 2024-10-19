#include <iostream>
#include <vector>
//#include <set>

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
    if(x != y){
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n < 3){
        cout << -1;
        return 0;
    }

    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, int>> graph_edges(m);
    vector<bool> is_used_edge(m + 1);
    vector<int> cnt(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph_edges[i] = make_pair(u, v);
        if(find_parent(parent, u) != find_parent(parent, v)){
            cnt[u]++;
            cnt[v]++;
            is_used_edge[i] = true;
            union_parent(parent, u, v);
        }
    }

    vector<int> root;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            root.push_back(i);
        }
    }

    if(root.size() > 2){
        cout << -1;
        return 0;
    }

    vector<vector<int>> tree_nodes(2);
    vector<vector<int>> tree_edges(2);

    if(root.size() == 1){
        for(int i = 0; i < m; i++){
            if(is_used_edge[i]){
                int u = graph_edges[i].first;
                int v = graph_edges[i].second;
                if((cnt[u] == 1 and u != root[0]) or (cnt[v] == 1 and v != root[0])){
                    int x = (cnt[u] == 1 and u != root[0]? u : v);
                    parent[x] = x;
                    root.push_back(x);
                    is_used_edge[i] = false;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == root[0]){
            tree_nodes[0].push_back(i);
        }else{
            tree_nodes[1].push_back(i);
        }
    }

    for(int i = 0; i < m; i++){
        if(is_used_edge[i]){
            int u = graph_edges[i].first;
            int v = graph_edges[i].second;
            if(find_parent(parent, u) == root[0]){
                tree_edges[0].push_back(i + 1);
            }else{
                tree_edges[1].push_back(i + 1);
            }
        }
    }

    if(tree_nodes[0].size() == tree_nodes[1].size()){
        cout << -1;
        return 0;
    }

    cout << tree_nodes[0].size() << " " << tree_nodes[1].size() << "\n";

    for(auto& node : tree_nodes[0]){
        cout << node << " ";
    }

    cout << "\n";

    for(auto& edge : tree_edges[0]){
        cout << edge << " ";
    }

    cout << "\n";

    for(auto& node : tree_nodes[1]){
        cout << node << " ";
    }

    cout << "\n";

    for(auto& edge : tree_edges[1]){
        cout << edge << " ";
    }

    return 0;
}