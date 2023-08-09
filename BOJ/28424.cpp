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
    if(x < y){
        swap(x, y);
    }
    parent[y] = x;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> max_alcohol(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> max_alcohol[i];
    }

    vector<int> parent(n + 2);
    for(int i = 1; i <= n + 1; i++){
        parent[i] = i;
    }

    vector<int> current_alcohol(n + 1);

    while(q--){
        int c;
        cin >> c;
        if(c == 1){
            int x, y;
            cin >> x >> y;
            for(int i = find_parent(parent, x); i <= n; i = find_parent(parent, i + 1)){
                if(y >= max_alcohol[i] - current_alcohol[i]){
                    y -= max_alcohol[i] - current_alcohol[i];
                    current_alcohol[i] = max_alcohol[i];
                    union_parent(parent, i, i + 1);
                }else{
                    current_alcohol[i] += y;
                    break;
                }
            }
        }else{
            int x;
            cin >> x;
            cout << current_alcohol[x] << "\n";
        }

    }

    return 0;
}