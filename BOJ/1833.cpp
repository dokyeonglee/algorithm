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

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int sum = 0;

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i][j] < 0){
                sum += -arr[i][j];
                union_parent(parent, i , j);
            }else{
                edges.emplace_back(arr[i][j], make_pair(i, j));
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<pair<int, int>> new_highways;

    for(auto& edge : edges){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            sum += c;
            new_highways.emplace_back(u + 1, v + 1);
            union_parent(parent, u, v);
        }
    }


    cout << sum << " " << new_highways.size() << "\n";
    for(auto& highway : new_highways){
        cout << highway.first << " " << highway.second << "\n";
    }


    return 0;
}