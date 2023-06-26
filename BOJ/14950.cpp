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

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    sort(edges.begin(), edges.end());

    long long answer = 0;
    int add = 0;

    for(int i = 0; i < m; i++){
        int pu = find_parent(parent, edges[i].second.first);
        int pv = find_parent(parent, edges[i].second.second);
        int c = edges[i].first;
        if(pu != pv){
            answer += c + add;
            add += t;
            union_parent(parent, pu, pv);
        }
    }

    cout << answer;

    return 0;
}