#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int r, int c, int num){

    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        arr[now.first][now.second] = num;

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c]){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

}

int bfs(vector<vector<int>>& arr){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));

    int num = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] and arr[i][j]){
                bfs(arr, visited, i, j, ++num);
            }
        }
    }

    return num;

}

vector<vector<int>> get_distance(vector<vector<int>>& arr, int number_of_island){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> distance(number_of_island + 1, vector<int>(number_of_island + 1, 987654321));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int r = i + dr[k];
                int c = j + dc[k];
                int cnt = 0;
                while(r >= 0 and r < n and c >= 0 and c < m and arr[r][c] == 0){
                    r += dr[k];
                    c += dc[k];
                    cnt++;
                }
                if(r >= 0 and r < n and c >= 0 and c < m and arr[i][j] != arr[r][c] and cnt > 1){
                    distance[arr[i][j]][arr[r][c]] = min(distance[arr[i][j]][arr[r][c]], cnt);
                }
            }
        }
    }

    return distance;

}

vector<pair<int, pair<int, int>>> get_edges(vector<vector<int>>& distance){

    vector<pair<int, pair<int, int>>> edges;

    for(int i = 1; i < distance.size(); i++){
        for(int j = i + 1; j < distance.size(); j++){
            if(distance[i][j] != 987654321 and distance[i][j] > 1){
                edges.push_back(make_pair(distance[i][j], make_pair(i, j)));
            }
        }
    }

    return edges;

}

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

int mst(vector<pair<int, pair<int, int>>>& edges, int number_of_island){

    sort(edges.begin(), edges.end());

    vector<int> parent(number_of_island + 1);
    for(int i = 1; i <= number_of_island; i++){
        parent[i] = i;
    }

    int result = 0;

    for(auto edge: edges){
        int c = edge.first;
        auto p = edge.second;
        if(find_parent(parent, p.first) != find_parent(parent, p.second)){
            union_parent(parent, p.first, p.second);
            result += c;
        }
    }

    int cnt = 0;

    for(int i = 1; i <= number_of_island; i++){
        if(find_parent(parent, i) == i){
            cnt++;
        }
    }

    if(cnt > 1){
        result = -1;
    }

    return result;

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int number_of_island = bfs(arr);
    vector<vector<int>> distance = get_distance(arr, number_of_island);
    vector<pair<int, pair<int, int>>> edges = get_edges(distance);

    cout << mst(edges, number_of_island);

    return 0;
}