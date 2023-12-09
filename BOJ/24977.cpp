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

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> edges(n);
    for(int i = 0; i < n; i++){
        cin >> edges[i].second.second >> edges[i].first;
        edges[i].second.first = i + 1;
    }

    sort(edges.begin(), edges.end(), greater<>());

    long long answer = 0;

    for(int i = 0; i < n; i++){

        int c = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if(find_parent(parent, u) != find_parent(parent, v)){
            answer += c;
            union_parent(parent, u, v);
        }
    }

    cout << answer;

    return 0;
}