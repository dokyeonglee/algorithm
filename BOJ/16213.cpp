#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

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
    if(x == y){
        return;
    }
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, pair<int, int>>> edges(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    vector<pair<int, int>> query(q + 1);
    for(int i = 1; i <= q; i++){
        cin >> query[i].first >> query[i].second;
    }

    sort(edges.begin() + 1, edges.end(), greater<>());

    vector<int> parent(n + 1);
    vector<int> left(q + 1, 1);
    vector<int> right(q + 1, m + 1);

    vector<vector<int>> mid(m + 1);
    vector<int> answer(q + 1, -1);

    while(1){
        bool check = false;
        for(int i = 1; i <= m; i++){
            mid[i].clear();
        }
        for(int i = 1; i <= q; i++){
            if(left[i] != right[i]){
                check = true;
                mid[(left[i] + right[i]) / 2].push_back(i);
            }
        }
        if(!check){
            break;
        }
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(int i = 1; i <= m; i++){
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int c = edges[i].first;
            union_parent(parent, u, v);
            for(int j : mid[i]){
                int pa = find_parent(parent, query[j].first);
                int pb = find_parent(parent, query[j].second);
                if(pa == pb){
                    answer[j] = c;
                    right[j] = i;
                }else{
                    left[j] = i + 1;
                }
            }
        }
    }

    for(int i = 1; i <= q; i++){
        cout << answer[i] << "\n";
    }
 
    return 0;
}