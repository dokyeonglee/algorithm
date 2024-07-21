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

    vector<int> parent(n);

    for(int i = 1; i < n; i++){
        parent[i] = i;
    }

    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = i + 1; j < n; j++){
            if(str[j] == 'Y'){
                edges.emplace_back(i, j);
            }
        }
    }

    if(edges.size() < m){
        cout << -1;
        return 0;
    }

    vector<int> answer(n);
    vector<bool> check(edges.size());

    int cnt = 0;

    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            answer[u]++;
            answer[v]++;
            union_parent(parent, u, v);
            check[i] = true;
            if(++cnt == n - 1){
                break;
            }
        }
    }

    if(cnt != n - 1){
        cout << -1;
    }else{
        if(cnt != m){
            for(int i = 0; i < edges.size(); i++){
                if(!check[i]){
                    int u = edges[i].first;
                    int v = edges[i].second;
                    answer[u]++;
                    answer[v]++;
                    if(++cnt == m){
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << answer[i] << " ";
        }
    }

    return 0;

}