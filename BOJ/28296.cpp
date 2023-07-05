#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<long long>& answer, vector<map<int, int>>& cnt, int x, int y, long long w){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(cnt[x].size() < cnt[y].size()){
        swap(x, y);
    }
    for(auto i : cnt[y]){
        int u = i.first;
        if(cnt[x].count(u)){
            answer[u] += cnt[x][u] * cnt[y][u] * w;
        }
        cnt[x][u] += cnt[y][u];
    }
    cnt[y].clear();
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> parent(n + 1);
    vector<map<int, int>> cnt(n + 1);
    vector<int> c(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        cnt[i][c[i]]++;
    }

    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }

    sort(edges.begin(), edges.end(), greater<>());

    vector<long long> answer(k + 1);

    for(auto edge : edges){
        long long w = edge.first;
        int pu = find_parent(parent, edge.second.first);
        int pv = find_parent(parent, edge.second.second);
        if(pu != pv){
            union_parent(parent, answer, cnt, pu, pv, w);
        }
    }

    for(int i = 1; i <= k; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}