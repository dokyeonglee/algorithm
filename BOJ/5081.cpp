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

    int s = 1;

    while(1){

        int n;
        cin >> n;

        if(n == 0){
            break;
        }

        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        vector<pair<int, int>> arr(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i].first >> arr[i].second;
        }

        for(int i = 1; i <= n; i++){
            int min_dist = 1987654321;
            vector<int> idx;
            for(int j = 1; j <= n; j++){
                if(i == j){
                    continue;
                }
                int dist = (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) + (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
                if(min_dist > dist){
                    min_dist = dist;
                    idx.clear();
                    idx.push_back(j);
                }else if(min_dist == dist){
                    idx.push_back(j);
                }
            }
            for(int j = 0; j < idx.size(); j++){
                if(find_parent(parent, i) != find_parent(parent, idx[j])){
                    union_parent(parent, i, idx[j]);
                }
            }
        }

        int answer = 0;
        for(int i = 1; i <= n; i++){
            if(find_parent(parent, i) == i){
                answer++;
            }
        }

        cout << "Sky " << s++ << " contains " << answer << " constellations.\n";
    }

    return 0;
}