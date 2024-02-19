#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> name(n + 1);
    vector<int> end_idx(n + 1);
    vector<int> next_idx(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> name[i];
        end_idx[i] = i;
    }

    int u, v;

    for(int i = 1; i < n; i++){
        cin >> u >> v;
        next_idx[end_idx[u]] = v;
        end_idx[u] = end_idx[v];
    }

    while(u){
        cout << name[u];
        u = next_idx[u];
    }


    return 0;
}