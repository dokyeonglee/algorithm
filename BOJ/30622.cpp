#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<long long>& distance, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        if(distance[x] > distance[y]){
            swap(x, y);
        }
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> parent(n + 1);
    vector<long long> distance(n + 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    map<pair<int, int>, int> mp;

    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        mp[make_pair(x, y)] = i;
        distance[i] = abs(x) + abs(y);
        for(int j = 0; j < 8; j++){
            auto next = make_pair(x + dr[j], y + dc[j]);
            if(mp.count(next)){
                union_parent(parent, distance, i, mp[next]);
            }
        }
    }

    long long answer = 0;
    long long max_dist = 0;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            answer += 2 * distance[i];
            max_dist = max(max_dist, distance[i]);
        }
    }

    answer -= max_dist;

    cout << answer;

    return 0;
}