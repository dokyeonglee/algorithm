#include <iostream>
#include <vector>

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

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(n + 1);
    vector<pair<int, int>> edges(m);
    
    for(auto& e : edges){
        cin >> e.first >> e.second;
    }

    vector<int> answer(k);

    for(int t = 0; t < k; t++){
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        int cnt = 0;
        int result = 0;
        for(int i = t; i < m; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            if(find_parent(parent, u) != find_parent(parent, v)){
                cnt++;
                result += i + 1;
                union_parent(parent, u, v);
            }
            if(cnt == n - 1){
                break;
            }
        }
        if(cnt != n - 1){
            break;
        }
        answer[t] = result;
    }

    for(auto& a : answer){
        cout << a << " ";
    }

    return 0;

}