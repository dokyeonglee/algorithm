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

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

vector<vector<pair<int, int>>> mst(vector<pair<int, pair<int, int>>>& edges, int n){

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<vector<pair<int, int>>> graph(n + 1);

    for(auto edge : edges){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, u, v);
            graph[u].push_back(make_pair(v, c));
            graph[v].push_back(make_pair(u, c));
        }
    }

    return graph;
}

long long dfs(vector<vector<pair<int, int>>>& graph, vector<long long>& dist, vector<bool>& leaf, int now){

    int cnt = 0;
    long long result = 0;

    for(auto e : graph[now]){
        int next = e.first;
        int cost = e.second;
        if(dist[next] == -1){
            cnt++;
            dist[next] = dist[now] + cost;
            result += dfs(graph, dist, leaf, next) + 2 * cost;
        }
    }

    leaf[now] = (cnt == 0);

    return result;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = make_pair(c, make_pair(u, v));
    }

    int src;
    cin >> src;

    sort(edges.begin(), edges.end(), greater<>());

    auto graph = mst(edges, n);

    vector<long long> dist(n + 1, -1);
    vector<bool> leaf(n + 1);

    dist[src] = 0;

    long long answer = dfs(graph, dist, leaf, src);
    long long max_dist = 0;

    for(int i = 1; i <= n; i++){
        if(leaf[i]){
            max_dist = max(max_dist, dist[i]);
        }
    }

    answer -= max_dist;

    cout << answer;

    return 0;
}