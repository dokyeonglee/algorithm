#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    vector<long long> sz(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        sz[u]++;
        sz[v]++;
        edges[i - 1] = make_pair(u, v);
    }

    long long d = 0;
    long long g = 0;

    for(auto e : edges){
        int u = e.first;
        int v = e.second;
        d += (long long)(sz[u] - 1) * (sz[v] - 1);
    }

    for(int i = 1; i <= n; i++){
        g += sz[i] * (sz[i] - 1) * (sz[i] - 2) / 6;
    }

    if(d > 3 * g){
        cout << 'D';
    }else if(d < 3 * g){
        cout << "G";
    }else{
        cout << "DUDUDUNGA";
    }

    return 0;
}