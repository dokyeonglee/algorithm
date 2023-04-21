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
    if(x > y){
        swap(x, y);
    }
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
    
    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u = find_parent(parent, u);
        v = find_parent(parent, v);
        while(u != v){
            union_parent(parent, u, v);
            v = find_parent(parent, v - 1);
        }
    }

    int answer = 0;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            answer++;
        }
    }

    cout << answer;

    return 0;
}