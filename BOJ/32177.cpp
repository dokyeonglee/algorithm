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

int distance_square(pair<int, int>& a, pair<int, int>& b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<pair<int, int>, pair<int, int>>> arr(n + 1);

    cin >> arr[0].first.first >> arr[0].first.second >> arr[0].second.first;

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }

    for(int i = 0; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(distance_square(arr[i].first, arr[j].first) <= k * k and abs(arr[i].second.first - arr[j].second.first) <= t){
                if(find_parent(parent, i) != find_parent(parent, j)){
                    union_parent(parent, i, j);
                }
            }
        }
    }

    int p = find_parent(parent, 0);
    
    vector<int> answer;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == p and arr[i].second.second == 1){
            answer.push_back(i);
        }
    }

    if(answer.size() == 0){
        cout << 0;
    }else{
        for(auto& x : answer){
            cout << x << " ";
        }
    }

    return 0;
}