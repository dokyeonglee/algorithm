#include <iostream>
#include <queue>

using namespace std;

vector<int> get_nodes_not_part_of_cycle(vector<vector<int>>& adj, vector<int>& in_degree){

    vector<int> result;

    queue<int> q;

    for(int i = 1; i < in_degree.size(); i++){
        if(in_degree[i] == 1){
            result.push_back(i);
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            if(--in_degree[next] == 1){
                result.push_back(next);
                q.push(next);
            }
        }
    }

    return result;

}

void dfs(vector<vector<int>>& adj, vector<bool>& is_cycle_node, vector<int>& root_nodes, int now, int root_node){
    root_nodes[now] = root_node;
    for(auto& next : adj[now]){
        if(!is_cycle_node[next] and root_nodes[next] == 0){
            dfs(adj, is_cycle_node, root_nodes, next, root_node);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        in_degree[u]++;
        in_degree[v]++;
    }

    vector<int> nodes_not_part_of_cycle = get_nodes_not_part_of_cycle(adj, in_degree);
    vector<bool> is_cycle_node(n + 1, true);

    for(int& node : nodes_not_part_of_cycle){
        is_cycle_node[node] = false;
    }

    vector<int> root_nodes(n + 1);
    
    for(int i = 1; i <= n; i++){
        if(is_cycle_node[i]){
            dfs(adj, is_cycle_node, root_nodes, i, i);
        }
    }

    while(q--){
        int u, v;
        cin >> u >> v;
        if(root_nodes[u] == root_nodes[v]){
            cout << "1\n";
        }else{
            cout << "2\n";
        }
    }

    return 0;
}