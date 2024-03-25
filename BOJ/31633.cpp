#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

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

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> parent(n * m + 1);

    for(int i = 1; i <= n * m; i++){
        parent[i] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 2; k++){
                int r = i + dr[k];
                int c = j + dc[k];
                if(r < 0 or r >= n or c < 0 or c >= m){
                    continue;
                }
                if(arr[i][j] == arr[r][c]){
                    union_parent(parent, i * m + j, r * m + c);
                }
            }
        }
    }

    vector<int> answer(n * m);
    vector<vector<int>> adj(n * m + 1);
    vector<int> in_degree(n * m + 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < 4; k++){
                int r = i + dr[k];
                int c = j + dc[k];
                if(r < 0 or r >= n or c < 0 or c >= m){
                    continue;
                }
                if(arr[i][j] < arr[r][c]){
                    adj[find_parent(parent, i * m + j)].push_back(find_parent(parent, r * m + c));
                    in_degree[find_parent(parent, r * m + c)]++;
                }
            }
        }
    }

    queue<int> q;

    for(int i = 0; i < n * m; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& next : adj[now]){
            answer[next] = max(answer[next], answer[now] + 1);
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int now = find_parent(parent, i * m + j);
            cout << answer[now] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}