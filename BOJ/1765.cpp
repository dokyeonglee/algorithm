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

    int n;
    cin >> n;

    vector<int> friends(n + 1);
    vector<vector<int>> enemys(n + 1);

    for(int i = 1; i <= n; i++){
        friends[i] = i;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){

        char c;
        int u, v;

        cin >> c >> u >> v;

        if(c == 'E'){
            enemys[u].push_back(v);
            enemys[v].push_back(u);
        }else{
            union_parent(friends, u, v);
        }
        
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < enemys[i].size(); j++){
            for(int k = 0; k < enemys[enemys[i][j]].size(); k++){
                union_parent(friends, i, enemys[enemys[i][j]][k]);
            }
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(find_parent(friends, i) == i){
            answer++;
        }
    }

    cout << answer;

    return 0;
}