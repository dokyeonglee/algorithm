#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
int min_cost = 1e9;

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

bool is_tree(vector<pair<int, pair<int, int>>>& edges, vector<int>& degree_limit, vector<int>& selected){

    int n = degree_limit.size() - 1;

    vector<int> parent(n + 1);
    vector<int> degree(degree_limit);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(int& s : selected){

        int c = edges[s].first;
        int u = edges[s].second.first;
        int v = edges[s].second.second;

        if(degree[u]-- == 0){
            return false;
        }
        if(degree[v]-- == 0){
            return false;
        }

        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, u, v);
        }else{
            return false;
        }

    }

    return true;

}

void dfs(vector<pair<int, pair<int, int>>>& edges, vector<int>& degree_limit, vector<int>& selected, int idx, int depth, int sum){

    if(depth == selected.size()){

        if(sum < min_cost){
            if(is_tree(edges, degree_limit, selected)){
                min_cost = sum;
                answer = selected;
            }
        }

        return;    
    }

    for(int i = idx; i < edges.size(); i++){
        selected[depth] = i;
        dfs(edges, degree_limit, selected, i + 1, depth + 1, sum + edges[i].first);
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n == 1){
        cout << "YES";
        return 0;
    }

    if(m < n - 1){
        cout << "NO";
        return 0;
    }

    vector<pair<int, pair<int, int>>> edges(m);
    vector<int> degree_limit(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> degree_limit[i];
    }

    for(auto& edge : edges){
        cin >> edge.second.first >> edge.second.second >> edge.first;
    }

    vector<int> selected(n - 1);

    dfs(edges, degree_limit, selected, 0, 0, 0);

    if(answer.size() == 0){
        cout << "NO";
    }else{
        cout << "YES\n";
        for(auto& x : answer){
            cout << edges[x].second.first << " " << edges[x].second.second << "\n";
        }        
    }

    return 0;
}