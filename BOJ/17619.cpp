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
    if(x != y){
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<pair<int, int>, int>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        int y;
        arr[i].second = i;
        cin >> arr[i].first.first >> arr[i].first.second >> y;
    }

    sort(arr.begin() + 1, arr.end());

    int e = arr[1].first.second;
    int now = arr[1].second;

    for(int i = 2; i <= n; i++){
        if(e < arr[i].first.first){
            now = arr[i].second;
        }else{
            union_parent(parent, now, arr[i].second);
        }
        if(e <= arr[i].first.second){
            e = arr[i].first.second;
        }
    }

    while(q--){
        int a, b;
        cin >> a >> b;
        if(find_parent(parent, a) == find_parent(parent, b)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }

    return 0;
}