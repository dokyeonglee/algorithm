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

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;

    vector<int> parent1(n + 1);
    vector<int> parent2(n + 1);
    vector<int> parent3(n + 1);

    for(int i = 1; i <= n; i++){
        parent1[i] = i;
        parent2[i] = i;
        parent3[i] = i;
    }

    for(int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent1, u) != find_parent(parent1, v)){
            union_parent(parent1, u, v);
        }
    }

    for(int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent2, u) != find_parent(parent2, v)){
            union_parent(parent2, u, v);
        }
    }

    for(int i = 0; i < m3; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent3, u) != find_parent(parent3, v)){
            union_parent(parent3, u, v);
        }
    }

    map<pair<int, pair<int, int>>, vector<int>> mp;

    for(int i = 1; i <= n; i++){
        int a = find_parent(parent1, i);
        int b = find_parent(parent2, i);
        int c = find_parent(parent3, i);
        mp[make_pair(a, make_pair(b, c))].push_back(i);
    }

    vector<vector<int>> answer;

    for(auto i : mp){
        if(i.second.size() > 1){
            answer.push_back(i.second);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";

    for(int i = 0; i < answer.size(); i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}