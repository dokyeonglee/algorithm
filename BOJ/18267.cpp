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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    string str;
    cin >> str;

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent, u) != find_parent(parent, v) and str[u - 1] == str[v - 1]){
            union_parent(parent, u, v);
        }
    }

    string answer(m, '0');

    for(int i = 0; i < m; i++){
        int u, v;
        char milk;
        cin >> u >> v >> milk;
        if(find_parent(parent, u) != find_parent(parent, v) or str[u - 1] == milk){
            answer[i] = '1';
        }        
    }

    cout << answer;

    return 0;
}