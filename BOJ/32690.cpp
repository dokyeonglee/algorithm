#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b){
    return a.first.second < b.first.second;
}

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<pair<pair<int, int>, int>> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }

    sort(arr.begin() + 1, arr.end());

    for(int i = 2; i <= n; i++){
        if(arr[i].first.first == arr[i - 1].first.first){
            union_parent(parent, sz, arr[i].second, arr[i - 1].second);
        }
    }

    sort(arr.begin() + 1, arr.end(), compare);

    for(int i = 2; i <= n; i++){
        if(arr[i].first.second == arr[i - 1].first.second){
            union_parent(parent, sz, arr[i].second, arr[i - 1].second);
        }
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, arr[i].second) == arr[i].second){
            cnt++;
        }
    }

    pair<int, int> answer;

    if(cnt > 1){

        int max_sz = 0;
        int max_idx = -1;
        int second_max_sz = 0;
        int second_max_idx = -1;

        for(int i = 1; i <= n; i++){
            if(find_parent(parent, arr[i].second) == arr[i].second){
                if(sz[arr[i].second] >= max_sz){
                    second_max_sz = max_sz;
                    second_max_idx = max_idx;
                    max_sz = sz[arr[i].second];
                    max_idx = i;
                }else if(sz[arr[i].second] > second_max_sz){
                    second_max_idx = i;
                    second_max_sz = sz[arr[i].second];
                }
            }
        }

        answer.first = arr[max_idx].first.first;
        answer.second = arr[second_max_idx].first.second;

    }else{

        answer.first = arr[1].first.first;
        answer.second = arr[1].first.second - 1;

        if(answer.second < -1e9){
            for(int i = 2; i <= n; i++){
                if(arr[i].first.second - arr[i - 1].first.second > 1){
                    answer.second = arr[i].first.second - 1;
                    break;
                }
            }
        }
        if(answer.second < -1e9){
            answer.second = 1e9;
        }
    }

    cout << answer.first << " " << answer.second;

    return 0;
}