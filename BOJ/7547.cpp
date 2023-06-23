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

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int test_case = 1; test_case <= t; test_case++){

        int n, m;
        cin >> n >> m;

        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        vector<pair<int, pair<int, int>>> edges(m);

        for(int i = 0; i < m; i++){
            cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        }

        sort(edges.begin(), edges.end(), greater<>());

        int answer = -1;

        for(int i = 0; i < m; i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int c = edges[i].first;
            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, u, v);
            }
            if(find_parent(parent, 1) == find_parent(parent, n)){
                answer = c;
                break;
            }
        }

        cout << "Scenario #" << test_case << ":\n" << answer << "\n\n";

    }

    return 0;
}