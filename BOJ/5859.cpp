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
    if(x != y){
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    n *= 2;

    vector<int> parent(n + 5);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int answer = 0;

    for(int i = 0; i < m; i++){
        int u, v;
        char c;
        cin >> u >> v >> c;
        if(c == 'T'){
            union_parent(parent, 2 * u, 2 * v);
            union_parent(parent, 2 * u + 1, 2 * v + 1);
        }else{
            union_parent(parent, 2 * u, 2 * v + 1);
            union_parent(parent, 2 * u + 1, 2 * v);
        }
        if(find_parent(parent, 2 * u) != find_parent(parent, 2 * u + 1)){
            answer++;
        }else{
            break;
        }
    }

    cout << answer;

    return 0;
}