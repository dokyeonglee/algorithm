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
    if(x != y){
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int answer = 0;

    int keep = 0;

    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;

        keep++;

        int result = 0;

        v = find_parent(parent, v);

        while(find_parent(parent, u) != v){
            int pu = find_parent(parent, u);
            union_parent(parent, pu + 1, pu);
            result++;
        }

        int temp = min(keep, result);

        keep -= temp;
        result -= temp;

        answer += result;
    }

    cout << answer;

    return 0;
}