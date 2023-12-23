#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, vector<int>& volume, vector<int>& rain, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        rain[x] += rain[y];
        volume[x] += volume[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<int> volume(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> volume[i];
    }

    int answer = 0;

    vector<int> rain(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> rain[i];
        if(rain[i] > volume[i]){
            answer++;
        }
    }
    
    while(q--){
        int c;
        cin >> c;
        if(c == 1){

            int u, v;
            cin >> u >> v;

            int pu = find_parent(parent, u);
            int pv = find_parent(parent, v);

            if(pu != pv){

                if(rain[pu] > volume[pu]){
                    answer -= sz[pu];
                }

                if(rain[pv] > volume[pv]){
                    answer -= sz[pv];
                }

                sz[pu] += sz[pv];
                rain[pu] += rain[pv];
                volume[pu] += volume[pv];
                parent[pv] = pu;

                if(rain[pu] > volume[pu]){
                    answer += sz[pu];
                }

            }

        }else{
            cout << answer << "\n";
        }
    }


    return 0;
}