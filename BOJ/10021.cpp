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

int get_distance_squared(pair<int, int>& a, pair<int, int>& b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int distance_squared = get_distance_squared(arr[i], arr[j]);
            if(distance_squared >= c){
                edges.emplace_back(distance_squared, make_pair(i, j));
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int cnt = 0;

    long long answer = 0;

    for(auto& e : edges){
        int u = e.second.first;
        int v = e.second.second;
        int c = e.first;
        if(find_parent(parent, u) != find_parent(parent, v)){
            cnt++;
            answer += c;
            union_parent(parent, u, v);
        }
        if(cnt == n - 1){
            break;
        }
    }

    if(cnt != n - 1){
        answer = -1;
    }

    cout << answer;

    return 0;

}