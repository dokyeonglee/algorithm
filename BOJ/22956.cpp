#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& height, vector<int>& rain, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(height[x] > height[y]){
        swap(x, y);
    }else if(height[x] == height[y]){
        if(rain[x] < rain[y]){
            swap(x, y);
        }
    }
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> parent(n * m);
    vector<int> height(n * m);
    vector<int> rain(n * m, -1);

    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> height[i * m + j];
        }
    }

    while(q--){
        int r, c, x;
        cin >> r >> c >> x;
        height[--r * m + --c] -= x;
        rain[r * m + c] = q;
        int p = find_parent(parent, r * m + c);
        if(p != r * m + c){
            if(height[r * m + c] < height[p]){
                parent[p] = r * m + c;
                parent[r * m + c] = r * m + c;
            }
        }else{
            for(int i = 0; i < 4; i++){
                int next_r = r + dr[i];
                int next_c = c + dc[i];
                if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                    continue;
                }
                if(rain[next_r * m + next_c] != -1){
                    if(find_parent(parent, r * m + c) != find_parent(parent, next_r * m + next_c)){
                        union_parent(parent, height, rain, r * m + c, next_r * m + next_c);
                    }
                }
            }

        }
        p = find_parent(parent, r * m + c);
        cout << p / m + 1 << " " << p % m + 1 << "\n";
    }


    

    return 0;
}