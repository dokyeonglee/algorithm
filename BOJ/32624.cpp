#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void get_parent(vector<vector<int>>& tree, vector<int>& parent, int root){

    queue<pair<int, int>> q;
    q.emplace(root, -1);

    while(!q.empty()){

        int now = q.front().first;
        int p = q.front().second;
        q.pop();

        for(auto& next : tree[now]){
            if(next != p){
                parent[next] = now;
                q.emplace(next, now);
            }
        }

    }
}

void get_number_of_nodes(vector<vector<int>>& tree, vector<int>& parent, vector<int>& number_of_nodes){

    queue<int> q;
    vector<int> sz(tree.size());

    for(int i = 1; i < tree.size(); i++){
        sz[i] = tree[i].size() - 1;
        if(sz[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int now = q.front();
        q.pop();

        if(parent[now] == -1){
            continue;
        }

        number_of_nodes[parent[now]] += number_of_nodes[now];

        if(--sz[parent[now]] == 0){
            q.push(parent[now]);
        }

    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(n + 1, -1);
    vector<int> number_of_nodes(n + 1, 1);

    get_parent(tree, parent, a);
    get_number_of_nodes(tree, parent, number_of_nodes);

    int idx = b;

    while(parent[idx] != a){
        idx = parent[idx];
    }

    int answer = number_of_nodes[idx] - number_of_nodes[b];

    cout << answer;

    return 0;
}