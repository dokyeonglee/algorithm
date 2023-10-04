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

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 5);
    for(int i = 1; i <= n + 4; i++){
        parent[i] = i;
    }

    vector<int> answer(n + 1);

    while(q--){
        int a, b, x;
        cin >> a >> b >> x;
        for(int i = find_parent(parent, a); parent[i] <= b; i = parent[i + 1]){
            if(answer[i] == 0){
                answer[i] = x;
            }
            union_parent(parent, i + 1, i);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << answer[i] << " ";
    }

    return 0;
}