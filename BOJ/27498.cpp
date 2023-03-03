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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges(m);

    int answer = 0;

    for(int i = 0; i < m; i++){

        int u, v, c, d;
        cin >> u >> v >> c >> d;

        edges[i] = make_pair(-c, make_pair(u, v));
		
        if(d == 1){
            union_parent(parent, u, v);
        }else{
        	answer += c;
        }
    }

    sort(edges.begin(), edges.end());

    for(auto edge: edges){
        auto [c, p] = edge;
        if(find_parent(parent, p.first) != find_parent(parent, p.second)){
            union_parent(parent, p.first, p.second);
			answer += c;
        }
    }

    cout << answer;

    return 0;
}