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

    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<int> arr(n + 1);

    for(int i = 0; i < m; i++){

        int a, b;
        cin >> a >> b;

        arr[a]++;
        arr[b]++;

        if(find_parent(parent, a) != find_parent(parent, b)){
            union_parent(parent, a, b);
        }

    }

    int cnt = 0;
    int cnt2 = 0;

    for(int i = 1; i <= n; i++){
        cnt += arr[i] % 2;
        if(find_parent(parent, i) == i){
            cnt2++;
        }
    }

    if(cnt2 == 1 and (cnt == 0 or cnt == 2)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}