#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> arr(n + 1);
    vector<int> cnt(m + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    vector<int> parent(n + 1);
    vector<map<int, int>> sz(n + 1);

    vector<pair<int, int>> edges(q + 1);

    for(int i = 1; i <= q; i++){
        cin >> edges[i].first >> edges[i].second;
    }

    vector<int> answer(m + 1, -1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i].clear();
        sz[i][arr[i]] = 1;
    }

    for(int i = 1; i <= q; i++){
        int p = find_parent(parent, edges[i].first);
        int p2 = find_parent(parent, edges[i].second);
        if(p == p2){
            continue;
        }
        if(sz[p].size() < sz[p2].size()){
            swap(p, p2);
        }
        for(auto it : sz[p2]){
            sz[p][it.first] += it.second;
            if(cnt[it.first] == sz[p][it.first]){
                if(answer[it.first] == -1){
                    answer[it.first] = i;
                }
            }
        }
        sz[p2].clear();
        parent[p2] = p;
    }

    for(int i = 1; i <= m; i++){
        if(cnt[i] == 1){
            cout << "0\n";
        }else{
            cout << answer[i] << "\n";
        }
    }
    
    return 0;
}