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

    int c, v;
    cin >> c >> v;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<int, pair<int, int>>> arr(m);
    for(int i = 0; i < m; i++){
        cin >> arr[i].second.first >> arr[i].second.second >> arr[i].first;
    }

    sort(arr.begin(), arr.end(), greater<>());

    for(int i = 0; i < m; i++){
        int x = find_parent(parent, arr[i].second.first);
        int y = find_parent(parent, arr[i].second.second);
        if(x != y){
            union_parent(parent, x, y);
        }
        if(find_parent(parent, c) == find_parent(parent, v)){
            cout << arr[i].first;
            return 0;
        }
    }

    return 0;
}