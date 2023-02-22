#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

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

    vector<int> parent(n * m);
    for(int i = 0; i < n * m; i++){
        parent[i] = i;
    }

    int dir;
    char d;

    for(int r = 0; r < n; r++){

        string str;
        cin >> str;

        for(int c = 0; c < m; c++){
    
            d = str[c];

            if(d == 'U'){
                dir = 0;
            }else if(d == 'R'){
                dir = 1;
            }else if(d == 'D'){
                dir = 2;
            }else{
                dir = 3;
            }

            int next_r = r + dr[dir];
            int next_c = c + dc[dir];

            union_parent(parent, r * m + c, next_r * m + next_c);
        
        }
    }

    int answer = 0;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(find_parent(parent, r * m + c) == r * m + c){
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}