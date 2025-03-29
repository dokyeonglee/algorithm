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

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n != m){
        cout << "NO";
    }else{

        vector<int> degree(n + 1);
        vector<int> parent(n + 1);

        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }

        int cnt_degree_three = 0;
        int cnt_degree_one = 0;
        int cnt_root = n;

        while(m--){
            int u, v;
            cin >> u >> v;
            if(degree[u]++ == 3){
                cout << "NO";
                return 0;
            }
            if(degree[v]++ == 3){
                cout << "NO";
                return 0;
            }
            if(find_parent(parent, u) != find_parent(parent, v)){
                union_parent(parent, u, v);
                cnt_root--;
            }
        }

        if(cnt_root > 1){
            cout << "NO";
            return 0;
        }

        for(int i = 1; i <= n; i++){
            if(degree[i] == 3){
                cnt_degree_three++;
            }else if(degree[i] == 1){
                cnt_degree_one++;
            }
        }

        if(cnt_degree_one != 1 or cnt_degree_three != 1){
            cout << "NO";
        }else{
            cout << "YES";
        }

    }

    return 0;

}