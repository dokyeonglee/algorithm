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

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> q(m);
    for(int i = 0; i < m; i++){
        cin >> q[i].first >> q[i].second.first;
        q[i].second.second = i;
    }

    sort(q.begin(), q.end(), greater<>());

    vector<int> answer(m);

    int max_step = 0;
    auto it = --mp.end();

    for(int i = 0; i < m; i++){
        int s = q[i].first;
        int d = q[i].second.first;
        int idx = q[i].second.second;
        auto temp = mp.upper_bound(s);
        if(temp != mp.end()){
            auto h = temp->first;
            while(it->first >= h){
                for(auto& x : it->second){
                    if(arr[x - 1] > s){
                        union_parent(parent, sz, x, x - 1);
                    }
                    if(arr[x + 1] > s){
                        union_parent(parent, sz, x, x + 1);
                    }
                    max_step = max(max_step, sz[find_parent(parent, x)]);
                }
                if(it == mp.begin()){
                    break;
                }
                it--;
            }
        }

        answer[idx] = (max_step < d);

    }

    for(int i = 0; i < m; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}