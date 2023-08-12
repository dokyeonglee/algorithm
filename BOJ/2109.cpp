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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
int m = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        m = max(m, arr[i].second);
    } 

    sort(arr.begin(), arr.end(), greater<>());

    vector<int> parent(m + 1);
    for(int i = 0; i <= m; i++){
        parent[i] = i;
    }

    int answer = 0;

    vector<int> earn(10001);

    for(int i = 0; i < n; i++){
        int p = arr[i].first;
        int d = find_parent(parent, arr[i].second);
        if(d and !earn[d]){
            earn[d] = p;
            answer += p;
            union_parent(parent, d - 1, d);
        }
    }

    cout << answer;

    return 0;
}